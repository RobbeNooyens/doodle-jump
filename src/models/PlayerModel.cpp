//
// Created by robnoo on 25/11/21.
//

#include <complex>
#include "PlayerModel.h"
#include "../controllers/EntityController.h"
#include "../World.h"
#include "../utils/Stopwatch.h"

void models::PlayerModel::update(double elapsed) {
    double elapsedSeconds = elapsed/1000000000;
    // Falling
    if(state == FALLING) {
        // Working
        this->t += elapsedSeconds;
        this->speed = acceleration*t;
        this->y += speed*t;


        auto box = getBox();
        CollisionBox cbox = {box.first, box.second};
        for(auto& platform: World::getInstance().getPlatforms()) {
            CollisionBox platformBox = platform->getCollisionBox();
            if(platformBox.collides(cbox)) {
                if(platformBox.upperLeft.second > cbox.lowerRight.second)
                    continue;
                state = JUMPING;
                double difference = cbox.lowerRight.second - platform->getCollisionBox().upperLeft.second;
                this->y -= difference;
                this->t = 0;
                this->speed = 10;
                this->y0 = y;
            }
        }
    } else if(state == JUMPING) {
        // Working
//        this->t += elapsedSeconds;
//        this->speed = acceleration*std::pow(t, 2);
//        double height = -std::pow((t-1), 2) + 1;
//        height *= 200;
//        this->y = y0 - height;
        this->t += elapsedSeconds;
        this->speed = acceleration*t;
        double difference = 5-(speed*t);
        this->y -= difference;

        if(difference < 0) {
            state = FALLING;
            speed = 2;
            t = 0;
        }
    }

    // Jumping


    // Left right
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        this->x -= 300*(elapsedSeconds);
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        this->x += 300*(elapsedSeconds);
    }



}

models::PlayerModel::PlayerModel() = default;
