/**
 *  ╒══════════════════════════════════════╕
 *  │                                      │
 *  │             Doodle Jump              │
 *  │        Advanced Programming          │
 *  │                                      │
 *  │            Robbe Nooyens             │
 *  │    s0201010@student.uantwerpen.be    │
 *  │                                      │
 *  │        University of Antwerp         │
 *  │                                      │
 *  ╘══════════════════════════════════════╛
 */

#include "EntityModel.h"
#include "../bounding_box/BoundingBox.h"

void EntityModel::setPosition(double x, double y) {
    this->x = x;
    this->y = y;
}

double EntityModel::getX() const {
    return x;
}

double EntityModel::getY() const {
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

void EntityModel::setRelativeBBox(const std::shared_ptr<BoundingBox> &bbox) {
    this->relativeBBox = bbox;
    updateBoundingBox();
}

std::shared_ptr<BoundingBox> EntityModel::getBoundingBox() {
    return absoluteBBox;
}

void EntityModel::updateBoundingBox() {
    absoluteBBox->setCenter({x,  y});
    absoluteBBox->setBorder(
            x-relativeBBox->getLeft()*size,
            y-relativeBBox->getTop()*sizeY,
            x+relativeBBox->getRight()*size,
            y+relativeBBox->getBottom()*sizeY);
}

EntityModel::EntityModel(): absoluteBBox(std::make_shared<BoundingBox>()) {}

EntityModel::~EntityModel() {
    absoluteBBox.reset();
    relativeBBox.reset();
}
