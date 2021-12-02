//
// Created by robnoo on 1/12/21.
//

#include "EntityModel.h"
#include "../utils/ResourceLoader.h"

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

std::pair<std::pair<double, double>, std::pair<double, double>> EntityModel::getBox() {
    return {{x-(bbox->left*size), y-(bbox->up*size)}, {x+(bbox->right*size), y+(bbox->down*size)}};
}

void EntityModel::setBoundingBox(std::shared_ptr<BoundingBox> &bbox) {
    this->bbox = bbox;
}
