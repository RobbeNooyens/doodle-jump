//
// Created by robnoo on 6/01/22.
//

#ifndef DOODLEJUMP_SFSPRITE_H
#define DOODLEJUMP_SFSPRITE_H


#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <memory>
#include <map>
#include "../SpriteWrapper.h"

class SFTexture;

class SFSprite: public SpriteWrapper {
public:
    void setTexture(const std::string &identifier) override;
    void setPosition(float x, float y) override;
    sf::Sprite& getSprite();

private:
    sf::Sprite sprite;
};


#endif //DOODLEJUMP_SFSPRITE_H
