//
// Created by robnoo on 6/01/22.
//

#include "SFSprite.h"

#include <utility>
#include "SFTexture.h"
#include "../../utils/TextureLoader.h"

void SFSprite::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}

sf::Sprite &SFSprite::getSprite() {
    return sprite;
}

void SFSprite::setScale(float factorX, float factorY) {
    sprite.setScale(factorX, factorY);
}

void SFSprite::setTexture(std::shared_ptr<TextureWrapper> &texture) {
    sprite.setTexture(std::static_pointer_cast<SFTexture>(texture)->getTexture());
}
