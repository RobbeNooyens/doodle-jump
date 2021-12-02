//
// Created by robnoo on 1/12/21.
//

#include "EntityModel.h"
#include "../utils/ResourceLoader.h"

void EntityModel::moveTo(double x, double y) {
    this->x = x;
    this->y = y;
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
    this->sizeY = (size*height)/width;
}

std::pair<std::pair<double, double>, std::pair<double, double>> EntityModel::getBox() {
    return {{x-((bbox->left) * size), y - (bbox->up * sizeY)}, {x + (bbox->right * size), y + (bbox->down * sizeY)}};
}

void EntityModel::setBoundingBox(std::shared_ptr<BoundingBox> &bbox) {
    this->bbox = bbox;
}

std::pair<double, double> EntityModel::getUpperLeftCorner() {
    return {x-(bbox->center.first * size), y - (bbox->center.second * sizeY)};
}

void EntityModel::setWidth(double w) {
    this->width = w;
}

void EntityModel::setHeight(double h) {
    this->height = h;
}
