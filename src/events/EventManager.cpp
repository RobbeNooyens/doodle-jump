//
// Created by robnoo on 1/12/21.
//

#include "EventManager.h"
#include "EventHandler.h"


void EventManager::registerHandler(std::shared_ptr<EventHandler> &handler) {
    handlers.push_back(handler);
}

void EventManager::invoke(std::shared_ptr<Event> &event) {
    for(const auto& handler: handlers) {
        handler->handle(*event);
    }
}

EventManager& EventManager::getInstance() {
    static EventManager INSTANCE;
    return INSTANCE;
}

EventManager::EventManager() = default;
