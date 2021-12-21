//
// Created by robnoo on 28/11/21.
//

#ifndef DOODLEJUMP_EVENT_H
#define DOODLEJUMP_EVENT_H

#include <chrono>
#include "../enums/EventType.h"

class Event {
public:
    explicit Event(EventType type): type(type) {}
    Event(): type(EventType::UNDEFINED) {}
    EventType getType() { return type; }

private:
    EventType type;
    std::chrono::system_clock::time_point timeStamp;
};

#endif //DOODLEJUMP_EVENT_H
