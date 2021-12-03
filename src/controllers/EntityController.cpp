//
// Created by robnoo on 2/12/21.
//

#include "EntityController.h"
#include "../views/EntityView.h"
#include "../models/EntityModel.h"
#include "../utils/ResourceLoader.h"

sf::Sprite &EntityController::getSprite() {
    return view->getSprite();
}

void EntityController::moveTo(double x, double y) {
    model->moveTo(x, y);
    view->moveTo(x, y);
}

CollisionBox EntityController::getCollisionBox() {
    auto box = model->getBox();
    return {box.first, box.second};
}

void EntityController::load(std::shared_ptr<Resource>& resource) {
    model->setBoundingBox(resource->boundingBox);
    model->setWidth(resource->width);
    model->setHeight(resource->height);
    view->setTexture(resource->texture);
    view->setWidth(resource->width);
    view->setHeight(resource->height);
}

void EntityController::setSize(double size) {
    model->setSize(size);
    view->setSize(size);
}

void EntityController::update(double elapsed) {
    model->update(elapsed);
    std::pair<double, double> corner = model->getUpperLeftCorner();
    view->moveTo(corner.first, corner.second);
}

void EntityController::link(std::shared_ptr<EntityController> &controller) {
    model->setController(controller);
    view->setController(controller);
}

bool CollisionBox::collides(CollisionBox &box) const {
    // Source: https://www.geeksforgeeks.org/find-two-rectangles-overlap/

    if (upperLeft.first == lowerRight.first || upperLeft.second == lowerRight.second || box.upperLeft.first == box.lowerRight.first
        || box.upperLeft.second == box.lowerRight.second) {
        // the line cannot have positive overlap
        return false;
    }

    // If one rectangle is on left side of other
    if (upperLeft.first >= box.lowerRight.first || box.upperLeft.first >= lowerRight.first)
        return false;

    // If one rectangle is above other
    if (lowerRight.second <= box.upperLeft.second || box.lowerRight.second <= upperLeft.second)
        return false;

    return true;
}
