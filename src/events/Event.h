//
// Created by robnoo on 28/11/21.
//

#ifndef DOODLEJUMP_EVENT_H
#define DOODLEJUMP_EVENT_H

#include <chrono>

enum EventType {NONE, KEY_PRESSED, REACHED_HEIGHT};

class Event {
public:
    explicit Event(EventType type): type(type) {}
    Event(): type(EventType::NONE) {}
    EventType getType() { return type; }

private:
    EventType type;
    std::chrono::system_clock::time_point timeStamp;
};

#endif //DOODLEJUMP_EVENT_H
