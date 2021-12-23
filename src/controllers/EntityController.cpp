//
// Created by robnoo on 2/12/21.
//

#include "EntityController.h"
#include "../views/EntityView.h"
#include "../models/EntityModel.h"
#include "../utils/ResourceLoader.h"
#include "../Settings.h"
#include "../events/EventManager.h"
#include "../bounding_box/BoundingBox.h"
#include "../utils/Random.h"
#include <iostream>

sf::Sprite &EntityController::getSprite() {
    return view->getSprite();
}

void EntityController::moveTo(double x, double y) {
    model->moveTo(x, y);
    view->moveTo(model->getX(), model->getY());
}

void EntityController::load(std::shared_ptr<Resource>& resource) {
    model->setWidth(resource->width);
    model->setHeight(resource->height);
    model->setRelativeBBox(resource->boundingBox);
    model->updateBoundingBox();
    view->setTexture(resource->texture);
    view->setWidth(resource->width);
    view->setHeight(resource->height);
    view->setBoundingBox(resource->boundingBox);
}

void EntityController::setSize(double size) {
    model->setSize(size);
    view->setSize(size);
}

void EntityController::update(double elapsed) {
    model->updateBoundingBox();
    model->update(elapsed);
    model->updateBoundingBox();
    view->moveTo(model->getX(), model->getY());
    if(model->getBoundingBox()->getTop() > settings::screenHeight+20) {
        destroy();
    }
}

void EntityController::link(std::shared_ptr<EntityController> &controller) {
    model->setController(controller);
    view->setController(controller);
}

void EntityController::destroy() {
    destroyed = true;
}

bool EntityController::isDestroyed() {
    return destroyed;
}

void EntityController::changeY(double value) {
    this->model->moveTo(model->getX(), model->getY() + value);
}

EntityController::EntityController(EntityType entityType): type(entityType) {
    id = Random::getInstance().generate(static_cast<long>(1e20));
}

EntityType EntityController::getType() {
    return type;
}

std::shared_ptr<BoundingBox> EntityController::getBoundingBox() {
    return model->getBoundingBox();
}

void EntityController::setDestroyed(bool d) {
    this->destroyed = d;
}

long EntityController::getId() {
    return id;
}
