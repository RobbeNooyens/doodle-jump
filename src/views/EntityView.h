//
// Created by robnoo on 28/11/21.
//

#ifndef DOODLEJUMP_ENTITYVIEW_H
#define DOODLEJUMP_ENTITYVIEW_H

#include <memory>

class EntityController;
class SpriteWrapper;

class EntityView {
public:
    explicit EntityView(std::shared_ptr<EntityController>& controller);

    // Getters
    const std::shared_ptr<SpriteWrapper>& getSprite();

    // Setters
    void setSize(double size);
    void setPosition(double x, double y);
    void setTexture(const std::string& textureId);

protected:
    double sizeX = 0, sizeY = 0;
    std::shared_ptr<SpriteWrapper> sprite;
    std::weak_ptr<EntityController> controller;
};

#endif //DOODLEJUMP_ENTITYVIEW_H
