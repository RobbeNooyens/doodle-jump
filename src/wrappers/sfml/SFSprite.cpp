//
// Created by robnoo on 6/01/22.
//

#include "SFSprite.h"

#include <utility>
#include "SFTexture.h"
#include "../../utils/TextureLoader.h"

void wrappers::sfml::SFSprite::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}

sf::Sprite &wrappers::sfml::SFSprite::getSprite() {
    return sprite;
}

void wrappers::sfml::SFSprite::setScale(float factorX, float factorY) {
    sprite.setScale(factorX, factorY);
}

void wrappers::sfml::SFSprite::setTexture(std::shared_ptr<TextureWrapper> &texture) {
    sprite.setTexture(std::static_pointer_cast<SFTexture>(texture)->getTexture());
}
