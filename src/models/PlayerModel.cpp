//
// Created by robnoo on 25/11/21.
//

#include <complex>
#include "PlayerModel.h"
#include "../controllers/EntityController.h"
#include "../World.h"
#include "../utils/Stopwatch.h"

void models::PlayerModel::update(double elapsed) {
    double elapsedMS = Stopwatch::getInstance().elapsedMillisecondsSinceLastCycle();
    // Falling
    if(state == FALLING) {
        this->t += elapsedMS/10000;
        this->speed = acceleration*t*t;
        this->y += speed;

        auto box = getBox();
        CollisionBox cbox = {box.first, box.second};
        for(auto& platform: World::getInstance().getPlatforms()) {
            if(platform->getCollisionBox().collides(cbox)) {
                state = JUMPING;
                double difference = cbox.lowerRight.second - platform->getCollisionBox().upperLeft.second;
                this->y -= difference;
                this->t = 0;
                this->speed = 10;
            }
        }
    } else if(state == JUMPING) {
        this->t += elapsedMS/10000;
        this->speed = acceleration*t*t;
        this->y -= jumpHeight-speed;

        if(speed > jumpHeight) {
            state = FALLING;
            speed = 0;
            t = 0;
        }
    }

    // Jumping


    // Left right
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        this->x -= 3*(elapsed);
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        this->x += 3*(elapsed);
    }



}

models::PlayerModel::PlayerModel() = default;
