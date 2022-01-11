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

    /**
     * @brief Reperesents an event when the player goes below the lower windowborder and dies
     */
    class PlayerDiedEvent : public Event {
    public:
        /**
         * @brief Default constructor
         */
        PlayerDiedEvent();

    };

}


#endif //DOODLEJUMP_PLAYERDIEDEVENT_H
