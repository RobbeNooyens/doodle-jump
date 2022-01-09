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

#ifndef DOODLEJUMP_ENTITYVIEW_H
#define DOODLEJUMP_ENTITYVIEW_H

#include <memory>
#include <string>

class EntityController;

namespace wrappers {
    class SpriteWrapper;
    class TextureWrapper;
}

class EntityView {
public:
    // Constructor - Destructor
    explicit EntityView(std::string spriteId);
    virtual ~EntityView();

    // Getters
    const std::shared_ptr<wrappers::SpriteWrapper>& getSprite();
    const std::shared_ptr<wrappers::TextureWrapper>& getTexture();

    // Setters
    void setSize(double size);
    void setPosition(double x, double y);
    void setTexture(const std::string& textureId);
    void setSprite(std::shared_ptr<wrappers::SpriteWrapper> spriteWrapper);

protected:
    const std::string spriteId;
    double size = 1, sizeX = 1, sizeY = 1;
    std::shared_ptr<wrappers::TextureWrapper> texture;
    std::shared_ptr<wrappers::SpriteWrapper> sprite;

    void updateSize();
};

#endif //DOODLEJUMP_ENTITYVIEW_H
