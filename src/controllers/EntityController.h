//
// Created by robnoo on 28/11/21.
//

#ifndef DOODLEJUMP_ENTITYCONTROLLER_H
#define DOODLEJUMP_ENTITYCONTROLLER_H

#include "../events/EventHandler.h"
#include "SFML/Graphics.hpp"

struct CollisionBox {
    std::pair<double, double> upperLeft;
    std::pair<double, double> lowerRight;
    // Source: https://www.geeksforgeeks.org/find-two-rectangles-overlap/
    bool collides(CollisionBox& box) {
        if (upperLeft.first == lowerRight.first || upperLeft.second == lowerRight.second || box.upperLeft.first == box.lowerRight.first
            || box.upperLeft.second == box.lowerRight.second) {
            // the line cannot have positive overlap
            return false;
        }

        // If one rectangle is on left side of other
        if (upperLeft.first >= box.lowerRight.first || box.upperLeft.first >= lowerRight.first)
            return false;

        // If one rectangle is above other
        if (lowerRight.second >= box.upperLeft.second || box.lowerRight.second >= upperLeft.second)
            return false;

        return true;
    }
};

class EntityController: public EventHandler {
public:
    void handle(std::shared_ptr<Event>& event) override = 0;
    virtual void load(double width) = 0;
    virtual sf::Sprite& getSprite() = 0;
    virtual void update(double elapsed) = 0;
    virtual void moveTo(double x, double y) = 0;
    virtual CollisionBox createCollisionBox() = 0;
};

#endif //DOODLEJUMP_ENTITYCONTROLLER_H
