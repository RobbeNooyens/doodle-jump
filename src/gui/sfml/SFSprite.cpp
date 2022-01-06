//
// Created by robnoo on 6/01/22.
//

#include "SFSprite.h"
#include "SFTexture.h"


void SFSprite::addTexture(std::string &identifier, std::shared_ptr<TextureWrapper> &texture) {
    textures.insert({identifier, std::static_pointer_cast<SFTexture>(texture)});
}

void SFSprite::applyTexture(std::string &identifier) {
    sprite.setTexture(textures.at(identifier)->getTexture());
}

void SFSprite::move(float x, float y) {
    sprite.move(x, y);
}
