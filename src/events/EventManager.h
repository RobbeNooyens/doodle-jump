//
// Created by robnoo on 1/12/21.
//

#ifndef DOODLEJUMP_EVENTMANAGER_H
#define DOODLEJUMP_EVENTMANAGER_H


#include <memory>
#include <vector>

class EventHandler;
class Event;

class EventManager {
public:
    void registerHandler(std::shared_ptr<EventHandler>& handler);
    void invoke(std::shared_ptr<Event>& event);
    static EventManager& getInstance();

private:
    EventManager();
    std::vector<std::shared_ptr<EventHandler>> handlers;


};


#endif //DOODLEJUMP_EVENTMANAGER_H