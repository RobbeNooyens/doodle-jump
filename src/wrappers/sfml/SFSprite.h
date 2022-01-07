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
    explicit SFSprite(std::string spriteId);
    void setTexture(const std::string &identifier) override;
    void setPosition(float x, float y) override;
    sf::Sprite& getSprite();

    const std::shared_ptr<TextureWrapper> &getTexture() override;

    void setScale(float factorX, float factorY) override;

private:
    const std::string spriteId;
    sf::Sprite sprite;
    std::shared_ptr<TextureWrapper> texture;
};


#endif //DOODLEJUMP_SFSPRITE_H
