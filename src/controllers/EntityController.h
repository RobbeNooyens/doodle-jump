//
// Created by robnoo on 28/11/21.
//

#ifndef DOODLEJUMP_ENTITYCONTROLLER_H
#define DOODLEJUMP_ENTITYCONTROLLER_H

#include "../events/EventHandler.h"

class EntityController: public EventHandler {
public:
    void handle(std::shared_ptr<Event>& event) override = 0;
    virtual void load(double width) = 0;
    virtual sf::Sprite& getSprite() = 0;
    virtual void update(double elapsed) = 0;
    virtual void moveTo(double x, double y) = 0;
};

#endif //DOODLEJUMP_ENTITYCONTROLLER_H
