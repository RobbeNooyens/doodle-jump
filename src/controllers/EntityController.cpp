//
// Created by robnoo on 2/12/21.
//

#include "EntityController.h"

#include <utility>
#include <iostream>
#include "../views/EntityView.h"
#include "../models/EntityModel.h"
#include "../Settings.h"
#include "../bounding_box/BoundingBox.h"
#include "../utils/Random.h"
#include "../wrappers/WindowWrapper.h"
#include "../wrappers/SpriteWrapper.h"
#include "../wrappers/TextureWrapper.h"

void EntityController::setPosition(double x, double y) {
    model->setPosition(x, y);
    view->setPosition(model->getX(), model->getY());
}

void EntityController::setSize(double size) {
    model->setSize(size);
    view->setSize(size);
}

void EntityController::update(double elapsed) {
    model->updateBoundingBox();
    model->update(elapsed);
    model->updateBoundingBox();
    view->setPosition(model->getX(), model->getY());
    if(model->getBoundingBox()->getTop() > settings::screenHeight) {
        goesBeneathScreen();
    }
}

void EntityController::destroy() {
    destroyed = true;
}

bool EntityController::isDestroyed() const {
    return destroyed;
}

void EntityController::changeY(double value) {
    this->model->setPosition(model->getX(), model->getY() + value);
}

EntityController::EntityController() {
    id = Random::getInstance().generate(static_cast<long>(1e20));
}

std::shared_ptr<BoundingBox> EntityController::getBoundingBox() {
    model->updateBoundingBox();
    return model->getBoundingBox();
}

void EntityController::setDestroyed(bool d) {
    this->destroyed = d;
}

long EntityController::getId() const {
    return id;
}

void EntityController::draw(std::shared_ptr<wrappers::WindowWrapper>& window) {
    window->draw(view->getSprite());
}

void EntityController::setTexture(const std::string &textureId) {
    view->setTexture(textureId);
    auto texture = view->getTexture();
    model->setRelativeBBox(texture->getBoundingBox());
    model->setWidth(texture->getWidth());
    model->setHeight(texture->getHeight());
}

void EntityController::setSprite(std::shared_ptr<wrappers::SpriteWrapper> sprite) {
    view->setSprite(std::move(sprite));
}

EntityController::~EntityController() {
    model.reset();
    view.reset();
}
