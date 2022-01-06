//
// Created by robnoo on 1/12/21.
//

#include "EntityModel.h"
#include "../utils/TextureLoader.h"
#include "../bounding_box/BoundingBox.h"

void EntityModel::setPosition(double x, double y) {
    this->x = x;
    this->y = y;
}

double EntityModel::getX() {
    return x;
}

double EntityModel::getY() {
    return y;
}

void EntityModel::setSize(double size) {
    this->size = size;
    this->sizeY = (size*height)/width;
}

void EntityModel::setWidth(double w) {
    this->width = w;
}

void EntityModel::setHeight(double h) {
    this->height = h;
}

void EntityModel::setRelativeBBox(std::shared_ptr<BoundingBox> &bbox) {
    this->relativeBBox = bbox;

}

std::shared_ptr<BoundingBox> EntityModel::getBoundingBox() {
    return absoluteBBox;
}

EntityModel::EntityModel() {
    absoluteBBox = std::make_shared<BoundingBox>();
}

void EntityModel::updateBoundingBox() {
    absoluteBBox->setCenter({x,  y});
    absoluteBBox->setBorder(
            x-relativeBBox->getLeft()*size,
            y-relativeBBox->getTop()*sizeY,
            x+relativeBBox->getRight()*size,
            y+relativeBBox->getBottom()*sizeY);
}

EntityModel::EntityModel(std::shared_ptr<EntityController> &controller): controller(controller) {}
