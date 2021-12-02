//
// Created by robnoo on 28/11/21.
//

#ifndef DOODLEJUMP_ENTITYCONTROLLER_H
#define DOODLEJUMP_ENTITYCONTROLLER_H

#include "../events/EventHandler.h"
#include "SFML/Graphics.hpp"

class EntityModel;
class EntityView;

struct CollisionBox {
    std::pair<double, double> upperLeft;
    std::pair<double, double> lowerRight;
    double width() const {return lowerRight.first - upperLeft.first;}
    double height() const {return lowerRight.second - upperLeft.second;}

    bool collides(CollisionBox& box) const;
};

class EntityController: public EventHandler {
public:
    void handle(std::shared_ptr<Event>& event) override = 0;
    virtual void load(double width) = 0;
    virtual void update(double elapsed) = 0;
    void moveTo(double x, double y);

    // Getters
    sf::Sprite& getSprite();
    CollisionBox getCollisionBox();

protected:
    std::shared_ptr<EntityModel> model;
    std::shared_ptr<EntityView> view;
};

#endif //DOODLEJUMP_ENTITYCONTROLLER_H
