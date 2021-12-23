//
// Created by robnoo on 25/11/21.
//

#include <complex>
#include <algorithm>
#include "PlayerModel.h"
#include "../controllers/EntityController.h"
#include "../World.h"
#include "../utils/Stopwatch.h"
#include "../events/ReachedNewHeightEvent.h"
#include "../events/EventManager.h"
#include "../ScoreManager.h"
#include "../bounding_box/BoundingBox.h"
#include "../Camera.h"

#define MAX_SPEED 15.0

void models::PlayerModel::update(double elapsed) {
    auto previousBottom = this->getBoundingBox()->getBottom();

    double absDifference = elapsed * acceleration;
    this->speed += (jumping() ? -1 : 1) * absDifference;
    this->y += (jumping() ? -1 : 1) * std::min(speed, MAX_SPEED) * boost * jumpHeight;

    updateBoundingBox();

    // Falling
    if(falling()) {
        auto bbox = getBoundingBox();
        // Check bonuses
        for(auto& bonus: World::getInstance().getBonuses()) {
            auto bonusBox = bonus->getBoundingBox();
            if(bonusBox->collides(bbox)) {
                if(previousBottom >= bonusBox->getTop())
                    continue;
                if(bbox->getBottom() < bonusBox->getTop())
                    continue;
                bounce(bonusBox->getTop());
                bonus->use();
                if(bonus->getType() == BonusType::SPRING) {
                    boost = 5;
                } else if(bonus->getType() == BonusType::JETPACK) {
                    speed = 40;
                    boost = 0.5;
                }
            }
        }
        // Check platforms
        for(auto& platform: World::getInstance().getPlatforms()) {
            auto platformBox = platform->getBoundingBox();
            if(platformBox->collides(bbox)) {
                if(previousBottom >= platformBox->getTop())
                    continue;
                if(bbox->getBottom() < platformBox->getTop())
                    continue;
                bounce(platformBox->getTop());
                platform->increaseJumpCount();
                if(platform->getType() == PlatformType::TEMPORARY) {
                    platform->destroy();
                }
            }
        }
    } else {
        if(speed <= 0) {
            verticalDirection = DOWN;
            speed = 0;
            boost = 1;
        }
    }

    // Update boost
    if(boost < 1) {
        boost *= (1+elapsed);
    } else if(boost > 1) {
        boost /= (1+elapsed);
    }

    if(y <= 200) {
        double difference = 200 - y;
        y = 200;
        this->highest += difference;
        std::shared_ptr<Event> newHeight = std::make_shared<ReachedNewHeightEvent>(difference, highest);
        EventManager::getInstance().invoke(newHeight);
        ScoreManager::getInstance().addScore(difference);
        Camera::getInstance().addHeight(difference);
    }


    // Left right
    if(moveXAxis) {
        if(horizontalDirection == LEFT) {
            this->x -= 300*(elapsed);
        } else if(horizontalDirection == RIGHT) {
            this->x += 300*(elapsed);
        }
    }
    moveXAxis = false;
}

bool models::PlayerModel::falling() {
    return verticalDirection == DOWN;
}

bool models::PlayerModel::jumping() {
    return verticalDirection == UP;
}

models::PlayerModel::PlayerModel(): EntityModel() {}

void models::PlayerModel::bounce(double from) {
    verticalDirection = UP;
    double difference = this->getBoundingBox()->getBottom() - from;
    this->y -= difference;
    this->speed = 10;
}

void models::PlayerModel::moveHorizontal(Direction direction) {
    horizontalDirection = direction;
    moveXAxis = true;
};
