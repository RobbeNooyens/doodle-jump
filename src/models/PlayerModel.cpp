//
// Created by robnoo on 25/11/21.
//

#include "PlayerModel.h"

void models::PlayerModel::update(double elapsed) {
    // Falling
    if(state == FALLING) {
        energie += elapsed;
        y += energie;
    }

    // Jumping

}

double models::PlayerModel::getX() {
    return x;
}

double models::PlayerModel::getY() {
    return y;
}

models::PlayerModel::PlayerModel(): bbox(BoundingBox(0, 0, 0, 0, 0, 0)) {}

void models::PlayerModel::setSize(double size) {
    this->size = size;
}

void models::PlayerModel::moveTo(double x, double y) {
    this->x = x;
    this->y = y;

}
