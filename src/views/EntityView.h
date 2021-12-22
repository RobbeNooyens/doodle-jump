//
// Created by robnoo on 28/11/21.
//

#ifndef DOODLEJUMP_ENTITYVIEW_H
#define DOODLEJUMP_ENTITYVIEW_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "../controllers/EntityController.h"

class EntityView {
public:
    EntityView();

    sf::Sprite& getSprite();
    void moveTo(double x, double y);
    void changeX(double increment);

    // Setters
    void setWidth(double w);
    void setHeight(double h);
    void setSize(double size);
    void setTexture(std::string& textureFile);
    void setTexture(sf::Texture& texture);
    void setController(std::shared_ptr<EntityController>& controller);
    void setBoundingBox(std::shared_ptr<BoundingBox>& bbox);

protected:
    sf::Texture texture;
    sf::Sprite sprite;
    double width = 0, height = 0;
    double sizeX = 0, sizeY = 0;
    std::weak_ptr<EntityController> controller;
    std::shared_ptr<BoundingBox> boundingBox;
};

#endif //DOODLEJUMP_ENTITYVIEW_H
