//
// Created by robnoo on 21/12/21.
//

#ifndef DOODLEJUMP_PLAYERCOLLISIONEVENT_H
#define DOODLEJUMP_PLAYERCOLLISIONEVENT_H


#include "Event.h"
#include "../controllers/EntityController.h"

class PlayerCollisionEvent: public Event {
public:
    PlayerCollisionEvent(const std::shared_ptr<EntityController>& entity);
};


#endif //DOODLEJUMP_PLAYERCOLLISIONEVENT_H
