//
// Created by robnoo on 28/11/21.
//

#ifndef DOODLEJUMP_EVENTHANDLER_H
#define DOODLEJUMP_EVENTHANDLER_H

class Event;

class EventHandler {
public:
    virtual void handle(Event& event) = 0;
};

#endif //DOODLEJUMP_EVENTHANDLER_H
