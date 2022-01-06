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
    void addTexture(std::string &identifier, std::shared_ptr<TextureWrapper> &texture) override;
    void applyTexture(std::string &identifier) override;

private:
    std::map<std::string, std::shared_ptr<SFTexture>> textures;
    sf::Sprite sprite;
};


#endif //DOODLEJUMP_SFSPRITE_H
