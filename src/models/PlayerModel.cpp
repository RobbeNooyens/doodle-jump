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
                direction = UP;
                double difference = bbox->getBottom() - bonusBox->getTop();
                this->y -= difference;
                this->speed = 10;
                this->y0 = y;
                bonus->use();
                if(bonus->getType() == BonusType::SPRING) {
                    boost = 5;
                } else if(bonus->getType() == BonusType::JETPACK) {
                    speed = 40;
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
                direction = UP;
                double difference = bbox->getBottom() - platformBox->getTop();
                this->y -= difference;
                this->speed = 10;
                this->y0 = y;
                if(platform->getType() == PlatformType::TEMPORARY) {
                    platform->destroy();
                }
            }
        }
    } else if(jumping()) {
        if(rocketPower > 0)
            this->rocketPower -= elapsed*100;
        if(rocketPower < 0)
            this->rocketPower = 0;

        if(speed <= 0) {
            direction = DOWN;
            speed = 0;
            boost = 0;
        }
    }

    // Update boost
    if(boost < 1) {
        boost = 1;
    } else if(boost > 1) {
        boost /= (1+elapsed);
    }

    if(y <= 200) {
        double difference = 200 - y;
        y = 200;
        this->highest += difference;
        std::shared_ptr<Event> newHeight = std::make_shared<ReachedNewHeightEvent>(difference, highest);
        EventManager::getInstance().invoke(newHeight);
        ScoreManager::getInstance().setScore(highest);
    }


    // Left right
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        this->x -= 300*(elapsed);
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        this->x += 300*(elapsed);
    }
}

bool models::PlayerModel::falling() {
    return direction == DOWN;
}

bool models::PlayerModel::jumping() {
    return direction == UP;
}

models::PlayerModel::PlayerModel(): EntityModel() {};
