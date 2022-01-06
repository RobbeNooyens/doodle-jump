//
// Created by robnoo on 28/11/21.
//

#include <utility>
#include "EntityView.h"
#include "../bounding_box/BoundingBox.h"
#include "../wrappers/SpriteWrapper.h"
#include "../wrappers/TextureWrapper.h"

void EntityView::setPosition(double x, double y) {
    auto center = sprite->getTexture()->getBoundingBox()->getCenter();
    float pixelX = x - center.first*(sizeX);
    float pixelY = y - center.second*(sizeY);
    sprite->setPosition(pixelX, pixelY);
}

void EntityView::setSize(double s) {
    auto texture = sprite->getTexture();
    double scale = s/texture->getWidth();
    sprite->setScale((float) scale, (float) scale);
    this->sizeX = s;
    this->sizeY = (s*texture->getHeight())/texture->getWidth();
}

void EntityView::setTexture(const std::string &textureId) {
    this->sprite->setTexture(textureId);
}

EntityView::EntityView(std::shared_ptr<EntityController>& controller):
    controller(controller) {}

const std::shared_ptr<SpriteWrapper> &EntityView::getSprite() {
    return sprite;
}
