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

    class Event {
    public:
        explicit Event(GameEventType type) : type(type) {}
        virtual ~Event() = default;

        Event() : type(GameEventType::UNDEFINED) {}

        GameEventType getType() { return type; }

    private:
        GameEventType type;
        std::chrono::system_clock::time_point timeStamp;
    };

}

#endif //DOODLEJUMP_EVENT_H
