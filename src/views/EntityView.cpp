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
