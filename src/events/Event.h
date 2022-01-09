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

#ifndef DOODLEJUMP_EVENT_H
#define DOODLEJUMP_EVENT_H

#include <chrono>
#include "../enums/GameEventType.h"

namespace events {

    /**
     * @brief Represents an event in the game
     */
    class Event {
    public:
        /**
         * @brief Parameter constructor
         * @param type event type
         */
        explicit Event(GameEventType type = UNDEFINED) : type(type) {}
        /**
         * @brief Default virtual destructor
         */
        virtual ~Event() = default;

        /**
         * @return game event type
         */
        GameEventType getType() { return type; }

    private:
        GameEventType type;
        std::chrono::system_clock::time_point timeStamp;
    };

}

#endif //DOODLEJUMP_EVENT_H
