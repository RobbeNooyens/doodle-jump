//
// Created by robnoo on 6/01/22.
//

#include "SFSprite.h"
#include "SFTexture.h"

void SFSprite::setPosition(float x, float y) {
    sprite.move(x, y);
}

sf::Sprite &SFSprite::getSprite() {
    return sprite;
}

void SFSprite::setTexture(const std::string &identifier) {

}
