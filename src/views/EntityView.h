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

/**
 * @brief Represents the entity rendering
 */
class EntityView {
public:
    // Constructor - Destructor
    /**
     * @brief Parameter constructor
     * @param spriteId sprite id used to retrieve textures
     */
    explicit EntityView(std::string spriteId);
    /**
     * @brief Virtual destructor
     */
    virtual ~EntityView();

    // Getters
    /**
     * @return spritewrapper
     */
    const std::shared_ptr<wrappers::SpriteWrapper>& getSprite();
    /**
     * @return current texture applied to the sprite
     */
    const std::shared_ptr<wrappers::TextureWrapper>& getTexture();

    // Setters
    /**
     * @param size width to scale the sprite to
     */
    void setSize(double size);
    /**
     * @param x new x coordinate
     * @param y new y coordinate
     */
    void setPosition(double x, double y);
    /**
     * @param textureId new texture id
     */
    void setTexture(const std::string& textureId);
    /**
     * @param spriteWrapper sprite to use for rendering
     */
    void setSprite(std::shared_ptr<wrappers::SpriteWrapper> spriteWrapper);

protected:
    /**
     * @brief Sprite id to retrieve textures for this entity
     */
    const std::string spriteId;
    /**
     * @brief Scaled width
     */
    double sizeX = 1;
    /**
     * @brief Scaled height
     */
    double sizeY = 1;
    /**
     * @brief current texture in use
     */
    std::shared_ptr<wrappers::TextureWrapper> texture{};
    /**
     * @brief sprite used for rendering entity
     */
    std::shared_ptr<wrappers::SpriteWrapper> sprite{};

    /**
     * @brief Synchronizes sizeX and sizeY width the texture in use
     */
    void updateSize();
};

#endif //DOODLEJUMP_ENTITYVIEW_H
