//
// Created by robnoo on 28/11/21.
//

#ifndef DOODLEJUMP_ENTITYVIEW_H
#define DOODLEJUMP_ENTITYVIEW_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class EntityView {
public:
    EntityView();
    sf::Sprite& getSprite();
    void setTexture(std::string& textureFile);
    void setTexture(sf::Texture& texture);
private:
    sf::Texture texture;
    sf::Sprite sprite;
};

#endif //DOODLEJUMP_ENTITYVIEW_H
