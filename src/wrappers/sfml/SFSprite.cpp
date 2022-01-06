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
    auto texture = std::static_pointer_cast<SFTexture>(TextureLoader::getInstance().getTexture(spriteId, identifier));
    sprite.setTexture(texture->getTexture());
}

SFSprite::SFSprite(std::string spriteId): spriteId(std::move(spriteId)) {}
