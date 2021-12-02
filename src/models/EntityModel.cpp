//
// Created by robnoo on 1/12/21.
//

#include "EntityModel.h"

void EntityModel::moveTo(double x, double y) {

}

double EntityModel::getX() {
    return x;
}

double EntityModel::getY() {
    return y;
}

std::pair<double, double> EntityModel::getCoordinates() {
    return {x,y};
}

void EntityModel::setSize(double size) {
    this->size = size;
}
