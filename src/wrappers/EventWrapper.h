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

#ifndef DOODLEJUMP_EVENTWRAPPER_H
#define DOODLEJUMP_EVENTWRAPPER_H

#include "../enums/WindowEventType.h"
#include "../enums/Keyboard.h"

namespace wrappers {

    class EventWrapper {
    public:
        virtual WindowEventType getType() = 0;

        virtual bool isKeyPressed(Keyboard key) = 0;

        virtual Keyboard getKey() = 0;

    };

}

#endif //DOODLEJUMP_EVENTWRAPPER_H
