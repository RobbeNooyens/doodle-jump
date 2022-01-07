//
// Created by robnoo on 1/12/21.
//

#ifndef DOODLEJUMP_EVENTMANAGER_H
#define DOODLEJUMP_EVENTMANAGER_H


#include <memory>
#include <vector>

class EventHandler;
class Event;

// TODO Memory leak

class EventManager {
public:
    void registerHandler(std::shared_ptr<EventHandler> handler);
    void invoke(std::shared_ptr<Event> event);
    static EventManager& getInstance();

    EventManager(EventManager()) = delete;
    void operator=(EventManager const&) = delete;
private:
    EventManager();
    std::vector<std::shared_ptr<EventHandler>> handlers;
};


#endif //DOODLEJUMP_EVENTMANAGER_H
