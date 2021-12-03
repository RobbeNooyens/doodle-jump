//
// Created by robnoo on 28/11/21.
//

#ifndef DOODLEJUMP_ENTITYCONTROLLER_H
#define DOODLEJUMP_ENTITYCONTROLLER_H

#include "../events/EventHandler.h"
#include "SFML/Graphics.hpp"

class EntityModel;
class EntityView;
class Resource;

struct CollisionBox {
    std::pair<double, double> upperLeft;
    std::pair<double, double> lowerRight;
    double width() const {return lowerRight.first - upperLeft.first;}
    double height() const {return lowerRight.second - upperLeft.second;}

    bool collides(CollisionBox& box) const;
};

class EntityController: public EventHandler {
public:
    // Abstracts
    virtual void update(double elapsed);
    void handle(std::shared_ptr<Event>& event) override = 0;

    // Actions
    void load(std::shared_ptr<Resource>& resource);
    void moveTo(double x, double y);
    void link(std::shared_ptr<EntityController>& controller);

    // Setters
    void setSize(double size);

    // Getters
    sf::Sprite& getSprite();
    CollisionBox getCollisionBox();

protected:
    std::shared_ptr<EntityModel> model;
    std::shared_ptr<EntityView> view;
};

#endif //DOODLEJUMP_ENTITYCONTROLLER_H
