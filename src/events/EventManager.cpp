//
// Created by robnoo on 1/12/21.
//

#include <iostream>
#include <algorithm>
#include "EventManager.h"
#include "EventHandler.h"
#include "Event.h"
#include "../utils/Random.h"

// TODO remove debug

void EventManager::registerHandler(std::shared_ptr<EventHandler> handler) {
//    std::cout << "Registering " << handler->getHandlerId() << std::endl;
    handlers.push_back(handler);
}

void EventManager::invoke(std::shared_ptr<Event> event) {
    if(event->getType() == KEY_PRESSED) {
        event->getType();
    }
    for(const auto& handler: handlers) {
        if(handler != nullptr)
            handler->handle(event);
    }
}

EventManager& EventManager::getInstance() {
    static EventManager INSTANCE;
    return INSTANCE;
}

unsigned long EventManager::generateId() {
    unsigned int result;
    bool available = false;
    while(!available) {
        result = Random::getInstance().generate<unsigned long>(static_cast<unsigned long>(1e20));
        available = true;
        for(auto& handler: handlers)
            available = available && result != handler->getHandlerId();
    }
    return result;
}

void EventManager::unregisterHandler(unsigned long id) {
//    std::cout << "Unregistering " << id << std::endl;
    int i;
    for(i = 0; i < handlers.size(); i++) {
        if(handlers[i]->getHandlerId() == id)
            break;
    }
    if(i < handlers.size()) {
//        std::cout << "Succesfully unregistered" << std::endl;
        handlers.erase(handlers.begin() + i);
    }
}

EventManager::EventManager() = default;
