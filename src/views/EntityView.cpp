//
// Created by robnoo on 28/11/21.
//

#include <stdexcept>
#include <iostream>
#include "EntityView.h"
#include "../bounding_box/BoundingBox.h"


sf::Sprite &EntityView::getSprite() {
    return sprite;
}

void EntityView::setTexture(std::string &textureFile) {
    // TODO: exception handling
    try {
        texture.loadFromFile("../resources/textures/" + textureFile);
        sprite.setTexture(texture);
    } catch(...) {
        throw std::runtime_error("Error while loading texture");
    }
}

EntityView::EntityView() = default;

void EntityView::setTexture(sf::Texture &newTexture) {
    texture = newTexture;
    sprite.setTexture(texture);
}

void EntityView::changeX(double increment) {
    sprite.setPosition((float) (sprite.getPosition().x + increment), sprite.getPosition().y);
}

void EntityView::moveTo(double x, double y) {
    float pixelX = x - boundingBox->getCenter().first*(sizeX);
    float pixelY = y - boundingBox->getCenter().second*(sizeY);
    sprite.setPosition(pixelX, pixelY);
}

void EntityView::setSize(double s) {
    double scale = s/width;
    sprite.setScale(scale, scale);
    this->sizeX = s;
    this->sizeY = (s*height)/width;
}

void EntityView::setWidth(double w) {
    this->width = w;
}

void EntityView::setHeight(double h) {
    this->height = h;
}

void EntityView::setController(std::shared_ptr<EntityController>& ctrl) {
    this->controller = ctrl;

}

void EntityView::setBoundingBox(std::shared_ptr<BoundingBox> &bbox) {
    this->boundingBox = bbox;
}
