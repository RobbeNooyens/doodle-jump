//
// Created by robnoo on 28/11/21.
//

#ifndef DOODLEJUMP_ENTITYCONTROLLER_H
#define DOODLEJUMP_ENTITYCONTROLLER_H

#include "../events/EventHandler.h"
#include "SFML/Graphics.hpp"
#include "../enums/EntityType.h"

class EntityModel;
class EntityView;
class Resource;
class BoundingBox;

class EntityController: public EventHandler {
public:
    // Constructor
    explicit EntityController(EntityType entityType);

    // Abstracts
    virtual void update(double elapsed);
    void handle(std::shared_ptr<Event>& event) override = 0;

    // Actions
    void load(std::shared_ptr<Resource>& resource);
    void moveTo(double x, double y);
    void changeY(double value);
    void link(std::shared_ptr<EntityController>& controller);
    void destroy();

    // Setters
    void setSize(double size);
    void setDestroyed(bool d);

    // Getters
    sf::Sprite& getSprite();
    std::shared_ptr<BoundingBox> getBoundingBox();
    bool isDestroyed();
    EntityType getType();

protected:
    std::shared_ptr<EntityModel> model;
    std::shared_ptr<EntityView> view;

private:
    bool destroyed = false;
    EntityType type;
};

#endif //DOODLEJUMP_ENTITYCONTROLLER_H
