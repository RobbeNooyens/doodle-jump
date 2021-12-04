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
    std::pair<double, double> getRelativeCenter() {return {(lowerRight.first - upperLeft.first) / 2, (lowerRight.second - upperLeft.second) / 2};}
    double width() const {return lowerRight.first - upperLeft.first;}
    double height() const {return lowerRight.second - upperLeft.second;}

    bool collides(CollisionBox& box) const;
};

class EntityController: public EventHandler {
public:
    // Constructor
    EntityController();

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

    // Getters
    sf::Sprite& getSprite();
    CollisionBox getCollisionBox();
    bool isDestroyed();

protected:
    std::shared_ptr<EntityModel> model;
    std::shared_ptr<EntityView> view;

private:
    bool destroyed = false;
    double screenHeight = 0;
};

#endif //DOODLEJUMP_ENTITYCONTROLLER_H
