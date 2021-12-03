//
// Created by robnoo on 25/11/21.
//

#include <complex>
#include "PlayerModel.h"
#include "../controllers/EntityController.h"
#include "../World.h"

void models::PlayerModel::update(double elapsed) {
    // Falling
    if(state == FALLING) {
        energie += elapsed;
        this->y += energie;

        auto box = getBox();
        CollisionBox cbox = {box.first, box.second};
        for(auto& platform: World::getInstance().getPlatforms()) {
            if(platform->getCollisionBox().collides(cbox)) {
                state = JUMPING;
                double difference = cbox.lowerRight.second - platform->getCollisionBox().upperLeft.second;
                this->y -= difference;
                energie = 1;
            }
        }
    } else if(state == JUMPING) {


        if(energie <= 0) {
            state = FALLING;
            energie = 0;
        }
    }

    // Jumping




}

models::PlayerModel::PlayerModel() = default;
