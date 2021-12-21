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

void EntityModel::setWidth(double w) {
    this->width = w;
}

void EntityModel::setHeight(double h) {
    this->height = h;
}

void EntityModel::setController(std::shared_ptr<EntityController> controller) {
    this->controller = controller;
}

std::shared_ptr<BoundingBox> EntityModel::getAbsoluteBBox() {
    return std::shared_ptr<BoundingBox>();
}

void EntityModel::setRelativeBBox(std::shared_ptr<BoundingBox> &bbox) {

}

void EntityModel::updateAbsoluteBBox() {


}
