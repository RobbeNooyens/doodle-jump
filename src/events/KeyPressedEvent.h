//
// Created by robnoo on 28/11/21.
//

#ifndef DOODLEJUMP_KEYPRESSEDEVENT_H
#define DOODLEJUMP_KEYPRESSEDEVENT_H


#include "Event.h"

enum KeyAction {MOVE_LEFT, MOVE_RIGHT, EXIT, PAUSE};

class KeyPressedEvent: public Event {
public:
    KeyPressedEvent(KeyAction action);
    KeyAction getAction();

private:
    KeyAction action;
};


#endif //DOODLEJUMP_KEYPRESSEDEVENT_H
