//
// Created by robnoo on 28/11/21.
//

#ifndef DOODLEJUMP_KEYPRESSEDEVENT_H
#define DOODLEJUMP_KEYPRESSEDEVENT_H


#include "Event.h"

enum KeyAction {LEFT, RIGHT, EXIT, PAUSE};

class KeyPressedEvent: public Event {
public:

private:
    KeyAction action;
};


#endif //DOODLEJUMP_KEYPRESSEDEVENT_H
