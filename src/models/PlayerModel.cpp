//
// Created by robnoo on 25/11/21.
//

#include <complex>
#include "PlayerModel.h"
#include "../controllers/EntityController.h"
#include "../World.h"
#include "../utils/Stopwatch.h"
#include "../events/ReachedNewHeightEvent.h"
#include "../events/EventManager.h"
#include "../ScoreManager.h"

void models::PlayerModel::update(double elapsed) {
    auto bboxBeforeMoving = this->getBox();
    // Falling
    if(state == FALLING) {
        // Working
        this->t += elapsed;
        this->speed = acceleration*t;
        this->y += speed*t;


        auto box = getBox();
        CollisionBox cbox = {box.first, box.second};
        // Check bonuses
        for(auto& bonus: World::getInstance().getBonuses()) {
            CollisionBox bonusBox = bonus->getCollisionBox();
            if(bonusBox.collides(cbox)) {
                if(bboxBeforeMoving.second.second >= bonusBox.upperLeft.second)
                    continue;
                if(bonusBox.upperLeft.second > cbox.lowerRight.second || bonusBox.lowerRight.second < cbox.lowerRight.second)
                    continue;
                state = JUMPING;
                double difference = cbox.lowerRight.second - bonusBox.upperLeft.second;
                this->y -= difference;
                this->t = 0;
                this->speed = 10;
                this->y0 = y;
                bonus->use();
                boost = 10;
            }
        }
        // Check platforms
        for(auto& platform: World::getInstance().getPlatforms()) {
            CollisionBox platformBox = platform->getCollisionBox();
            if(platformBox.collides(cbox)) {
                if(bboxBeforeMoving.second.second >= platformBox.upperLeft.second)
                    continue;
                if(platformBox.upperLeft.second > cbox.lowerRight.second || platformBox.lowerRight.second < cbox.lowerRight.second)
                    continue;
                state = JUMPING;
                double difference = cbox.lowerRight.second - platformBox.upperLeft.second;
                this->y -= difference;
                this->t = 0;
                this->speed = 10;
                this->y0 = y;
                if(platform->getType() == PlatformType::TEMPORARY) {
                    platform->destroy();
                }
            }
        }
    } else if(state == JUMPING) {
        // Working
//        this->t += elapsedSeconds;
//        this->speed = acceleration*std::pow(t, 2);
//        double height = -std::pow((t-1), 2) + 1;
//        height *= 200;
//        this->y = y0 - height;
        this->t += elapsed;
        this->speed = acceleration*t;
        double difference = (5-(speed*t))*boost;
        this->y -= difference;

        if(difference < 0) {
            state = FALLING;
            speed = 2;
            t = 0;
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
//        if(((int) ((highest-difference) / 60.0)) != ((int) (highest / 60.0))) {
//            World::getInstance().createPlatform();
//        }
        ScoreManager::getInstance().setScore(highest);
    }


    // Left right
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        this->x -= 300*(elapsed);
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        this->x += 300*(elapsed);
    }

}

models::PlayerModel::PlayerModel() = default;
