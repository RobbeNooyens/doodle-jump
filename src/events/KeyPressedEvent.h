/**
 *  ╒══════════════════════════════════════╕
 *  │                                      │
 *  │             Doodle Jump              │
 *  │        Advanced Programming          │
 *  │                                      │
 *  │            Robbe Nooyens             │
 *  │    s0201010@student.uantwerpen.be    │
 *  │                                      │
 *  │        University of Antwerp         │
 *  │                                      │
 *  ╘══════════════════════════════════════╛
 */

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
