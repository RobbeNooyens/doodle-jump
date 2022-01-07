//
// Created by robnoo on 28/11/21.
//

#include "EntityView.h"

#include <utility>
#include <iostream>
#include "../bounding_box/BoundingBox.h"
#include "../wrappers/SpriteWrapper.h"
#include "../wrappers/TextureWrapper.h"
#include "../utils/TextureLoader.h"

void EntityView::setPosition(double x, double y) {
    auto center = texture->getBoundingBox()->getCenter();
    float pixelX = x - center.first*(sizeX);
    float pixelY = y - center.second*(sizeY);
    sprite->setPosition(pixelX, pixelY);
}

void EntityView::setSize(double s) {
    this->size = s;
    if(texture)
        updateSize();
}

void EntityView::setTexture(const std::string &textureId) {
    texture = TextureLoader::getInstance().getTexture(spriteId, textureId);
    sprite->setTexture(texture);
    updateSize();
}

const std::shared_ptr<SpriteWrapper> &EntityView::getSprite() {
    return sprite;
}

void EntityView::updateSize() {
    double scale = size/texture->getWidth();
    sprite->setScale((float) scale, (float) scale);
    this->sizeX = size;
    this->sizeY = (size*texture->getHeight())/texture->getWidth();
}

void EntityView::setSprite(std::shared_ptr<SpriteWrapper> spriteWrapper) {
    this->sprite = std::move(spriteWrapper);
}

const std::shared_ptr<TextureWrapper> &EntityView::getTexture() {
    return texture;
}

EntityView::EntityView(std::string spriteId): spriteId(std::move(spriteId)) {}
