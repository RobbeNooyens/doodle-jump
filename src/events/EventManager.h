//
// Created by robnoo on 1/12/21.
//

#ifndef DOODLEJUMP_EVENTMANAGER_H
#define DOODLEJUMP_EVENTMANAGER_H


#include <memory>
#include <vector>

class EventHandler;

namespace events {
    class Event;
}

class EventManager {
public:
    void registerHandler(std::shared_ptr<EventHandler> handler);
    void unregisterHandler(unsigned long id);
    void invoke(std::shared_ptr<events::Event> event);

    static EventManager& getInstance();
    unsigned long generateId();

    EventManager(EventManager()) = delete;
    void operator=(EventManager const&) = delete;
private:
    EventManager();
    std::vector<std::shared_ptr<EventHandler>> handlers;
};


#endif //DOODLEJUMP_EVENTMANAGER_H
