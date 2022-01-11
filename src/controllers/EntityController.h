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

#ifndef DOODLEJUMP_ENTITYCONTROLLER_H
#define DOODLEJUMP_ENTITYCONTROLLER_H

#include "../events/EventHandler.h"

class EntityModel;
class EntityView;
class BoundingBox;

namespace wrappers {
    class WindowWrapper;
    class SpriteWrapper;
}

/**
 * @brief Represents an abstract game entity
 */
class EntityController: public EventHandler {
public:
    // Constructor
    /**
     * @brief Default constructor
     */
    EntityController();
    /**
     * @brief Virtual destructor
     */
    ~EntityController() override;

    // Abstracts
    /**
     * @brief Updates state based on elapsed seconds
     * @param elapsed seconds since last frame
     */
    virtual void update(double elapsed);
    /**
     * @brief Draws the entity view in the given window
     * @param window window to draw the entity in
     */
    virtual void draw(std::shared_ptr<wrappers::WindowWrapper>& window);
    /**
     * @brief Performs actions when the entity goes below the bottom screenedge
     */
    virtual void goesBeneathScreen() = 0;
    /**
     * @brief Handles incoming game events
     * @param event event that got invoked
     */
    void handle(std::shared_ptr<events::Event>& event) override = 0;

    // Actions
    /**
     * @brief Changes the entity's y-value
     * @param value distance to move down
     */
    void changeY(double value);
    /**
     * @brief Marks the entity as destroyed
     */
    void destroy();

    // Setters
    /**
     * @param size width to resize the entity to
     */
    void setSize(double size);
    /**
     * @param sprite sprite to use for this entity
     */
    void setSprite(std::shared_ptr<wrappers::SpriteWrapper> sprite);
    /**
     * @param textureId texture to activate for the current sprite
     */
    void setTexture(const std::string& textureId);
    /**
     * @param x new x position
     * @param y new y position
     */
    void setPosition(double x, double y);

    // Getters
    /**
     * @return entity bounding box with absolute x and y values
     */
    std::shared_ptr<BoundingBox> getBoundingBox();
    /**
     *
     * @return true if the object is marked as destroyed
     */
    [[nodiscard]] bool isDestroyed() const;
    /**
     *
     * @return entity id
     */
    [[nodiscard]] long getId() const;

protected:
    /**
     * @brief model handling all back-end functionality
     */
    std::shared_ptr<EntityModel> model{};
    /**
     * @brief view handling all front-end functionality
     */
    std::shared_ptr<EntityView> view{};

private:
    bool destroyed = false;
    long id = 0;
};

#endif //DOODLEJUMP_ENTITYCONTROLLER_H
