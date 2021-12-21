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

#define MAX_SPEED 15.0

void models::PlayerModel::update(double elapsed) {
    auto bboxBeforeMoving = this->getBox();

    double absDifference = elapsed * acceleration;
    this->speed += (jumping() ? -1 : 1) * absDifference;
    this->y += (jumping() ? -1 : 1) * std::min(speed, MAX_SPEED) * boost * jumpHeight;

    // Falling
    if(falling()) {
        auto box = getBox();
        AbsoluteBoundingBox cbox = {box.first, box.second};
        // Check bonuses
        for(auto& bonus: World::getInstance().getBonuses()) {
            AbsoluteBoundingBox bonusBox = bonus->getCollisionBox();
            if(bonusBox.collides(cbox)) {
                if(bboxBeforeMoving.second.second >= bonusBox.upperLeft.second)
                    continue;
                if(bonusBox.upperLeft.second > cbox.lowerRight.second || bonusBox.lowerRight.second < cbox.lowerRight.second)
                    continue;
                direction = UP;
                double difference = cbox.lowerRight.second - bonusBox.upperLeft.second;
                this->y -= difference;
                this->speed = 10;
                this->y0 = y;
                bonus->use();
                if(bonus->getType() == BonusType::SPRING) {
                    boost = 5;
                } else if(bonus->getType() == BonusType::JETPACK) {
                    rocketPower = 200;
                }
            }
        }
        // Check platforms
        for(auto& platform: World::getInstance().getPlatforms()) {
            AbsoluteBoundingBox platformBox = platform->getCollisionBox();
            if(platformBox.collides(cbox)) {
                if(bboxBeforeMoving.second.second >= platformBox.upperLeft.second)
                    continue;
                if(platformBox.upperLeft.second > cbox.lowerRight.second || platformBox.lowerRight.second < cbox.lowerRight.second)
                    continue;
                direction = UP;
                double difference = cbox.lowerRight.second - platformBox.upperLeft.second;
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

models::PlayerModel::PlayerModel() = default;
