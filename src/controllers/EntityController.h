//
// Created by robnoo on 28/11/21.
//

#ifndef DOODLEJUMP_ENTITYCONTROLLER_H
#define DOODLEJUMP_ENTITYCONTROLLER_H

#include "../events/EventHandler.h"
#include "../enums/EntityType.h"

class EntityModel;
class EntityView;
class BoundingBox;
class WindowWrapper;
class SpriteWrapper;

class EntityController: public EventHandler {
public:
    // Constructor
    EntityController();
    virtual ~EntityController();

    // Abstracts
    virtual void update(double elapsed);
    virtual void draw(std::shared_ptr<WindowWrapper>& window);
    void handle(std::shared_ptr<Event>& event) override = 0;

    // Actions
    void changeY(double value);
    void destroy();

    // Setters
    void setSize(double size);
    void setSprite(std::shared_ptr<SpriteWrapper> sprite);
    void setTexture(const std::string& textureId);
    void setPosition(double x, double y);
    void setDestroyed(bool d);

    // Getters
    std::shared_ptr<BoundingBox> getBoundingBox();
    [[nodiscard]] bool isDestroyed() const;
    [[nodiscard]] long getId() const;

protected:
    std::shared_ptr<EntityModel> model;
    std::shared_ptr<EntityView> view;

private:
    bool destroyed = false;
    long id = 0;
};

#endif //DOODLEJUMP_ENTITYCONTROLLER_H
