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
class WindowWrapper;

class EntityController: public EventHandler, public std::enable_shared_from_this<EntityController> {
public:
    // Constructor
    EntityController();

    // Abstracts
    virtual void update(double elapsed);
    virtual void draw(std::shared_ptr<WindowWrapper>& window);
    void handle(std::shared_ptr<Event>& event) override = 0;

    // Actions
    void changeY(double value);
    void destroy();

    // Setters
    void setSize(double size);
    void setPosition(double x, double y);
    void setDestroyed(bool d);

    // Getters
    std::shared_ptr<BoundingBox> getBoundingBox();
    bool isDestroyed() const;
    long getId() const;

private:
    std::shared_ptr<EntityModel> model;
    std::shared_ptr<EntityView> view;

    bool destroyed = false;
    long id = 0;
};

#endif //DOODLEJUMP_ENTITYCONTROLLER_H
