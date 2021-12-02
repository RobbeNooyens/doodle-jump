//
// Created by robnoo on 25/11/21.
//

#include "PlayerModel.h"

void models::PlayerModel::update(double elapsed) {
    // Falling
    if(state == FALLING) {
        energie += elapsed;
        this->y += energie;
    }

    // Jumping




}

models::PlayerModel::PlayerModel() = default;
