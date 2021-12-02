//
// Created by robnoo on 28/11/21.
//

#include <stdexcept>
#include "EntityView.h"



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

EntityView::EntityView() {
}

void EntityView::setTexture(sf::Texture &newTexture) {
    texture = newTexture;
    sprite.setTexture(texture);
}

void EntityView::changeX(double increment) {
    sprite.setPosition((float) (sprite.getPosition().x + increment), sprite.getPosition().y);
}

void EntityView::moveTo(double x, double y) {
    sprite.setPosition((float) x, (float) y);
}

void EntityView::setSize(double size) {
    sprite.setScale(size, size);
}