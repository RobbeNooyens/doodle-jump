//
// Created by robnoo on 28/11/21.
//

#ifndef DOODLEJUMP_KEYPRESSEDEVENT_H
#define DOODLEJUMP_KEYPRESSEDEVENT_H


#include "Event.h"
#include "../enums/Keyboard.h"

namespace events {

    class KeyPressedEvent : public Event {
    public:
        explicit KeyPressedEvent(Keyboard key);

        Keyboard getKey();

    private:
        Keyboard keyPressed;
    };

}


#endif //DOODLEJUMP_KEYPRESSEDEVENT_H
