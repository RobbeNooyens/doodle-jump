//
// Created by robnoo on 28/11/21.
//

#include "EntityView.h"



sf::Sprite &EntityView::getSprite() {
    return sprite;
}

void EntityView::setTexture(std::string &textureFile) {
    // TODO: exception handling
    texture.loadFromFile("resources/textures/" + textureFile);
}

EntityView::EntityView() {
    sprite.setTexture(texture);
}
