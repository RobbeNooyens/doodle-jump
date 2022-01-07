//
// Created by robnoo on 6/01/22.
//

#include "SFSprite.h"

#include <utility>
#include "SFTexture.h"
#include "../../utils/TextureLoader.h"

void SFSprite::setPosition(float x, float y) {
    sprite.move(x, y);
}

sf::Sprite &SFSprite::getSprite() {
    return sprite;
}

void SFSprite::setTexture(const std::string &identifier) {
    texture = TextureLoader::getInstance().getTexture(spriteId, identifier);
    sprite.setTexture(std::static_pointer_cast<SFTexture>(texture)->getTexture());
}

SFSprite::SFSprite(std::string spriteId): spriteId(std::move(spriteId)) {}

const std::shared_ptr<TextureWrapper> &SFSprite::getTexture() {
    return texture;
}

void SFSprite::setScale(float factorX, float factorY) {

}
