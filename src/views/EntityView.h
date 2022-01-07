//
// Created by robnoo on 28/11/21.
//

#ifndef DOODLEJUMP_ENTITYVIEW_H
#define DOODLEJUMP_ENTITYVIEW_H

#include <memory>
#include <string>

class EntityController;
class SpriteWrapper;
class TextureWrapper;

class EntityView {
public:
    explicit EntityView(std::string spriteId);

    // Getters
    const std::shared_ptr<SpriteWrapper>& getSprite();
    const std::shared_ptr<TextureWrapper>& getTexture();

    // Setters
    void setSize(double size);
    void setPosition(double x, double y);
    void setTexture(const std::string& textureId);
    void setSprite(std::shared_ptr<SpriteWrapper>& spriteWrapper);

protected:
    const std::string spriteId;
    double size = 1, sizeX = 1, sizeY = 1;
    std::shared_ptr<TextureWrapper> texture;
    std::shared_ptr<SpriteWrapper> sprite;

    void updateSize();
};

#endif //DOODLEJUMP_ENTITYVIEW_H
