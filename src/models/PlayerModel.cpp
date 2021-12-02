//
// Created by robnoo on 25/11/21.
//

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
            }
        }
    }

    // Jumping




}

models::PlayerModel::PlayerModel() = default;
