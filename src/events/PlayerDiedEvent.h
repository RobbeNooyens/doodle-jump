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

#ifndef DOODLEJUMP_PLAYERDIEDEVENT_H
#define DOODLEJUMP_PLAYERDIEDEVENT_H


#include "Event.h"

namespace events {

    class PlayerDiedEvent : public Event {
    public:
        PlayerDiedEvent();

    };

}


#endif //DOODLEJUMP_PLAYERDIEDEVENT_H
