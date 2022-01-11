/**
 *  ╒══════════════════════════════════════╕
 *  │                                      │
 *  │             Doodle Jump              │
 *  │        Advanced Programming          │
 *  │                                      │
 *  │            Robbe Nooyens             │
 *  │    s0201010@student.uantwerpen.be    │
 *  │                                      │
 *  │        University of Antwerp         │
 *  │                                      │
 *  ╘══════════════════════════════════════╛
 */

#include "SFSprite.h"

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
