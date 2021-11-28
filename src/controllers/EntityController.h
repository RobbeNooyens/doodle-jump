//
// Created by robnoo on 28/11/21.
//

#ifndef DOODLEJUMP_ENTITYCONTROLLER_H
#define DOODLEJUMP_ENTITYCONTROLLER_H

#include "../events/EventHandler.h"

class EntityController: public EventHandler {
public:
    void handle(Event& event) override = 0;
    virtual void load(std::string& entityJsonFile) = 0;
    virtual sf::Sprite getSprite() = 0;
};

#endif //DOODLEJUMP_ENTITYCONTROLLER_H
