//
// Created by robnoo on 1/12/21.
//

#include <iostream>
#include <algorithm>
#include "EventManager.h"
#include "EventHandler.h"
#include "Event.h"

void EventManager::registerHandler(std::shared_ptr<EventHandler> handler) {
    handlers.push_back(handler);
}

void EventManager::invoke(std::shared_ptr<Event> event) {
    for(const auto& handler: handlers)
        handler->handle(event);
    switch (event->getType()) {
        case UNDEFINED:
            std::cout << "event: undefined" << std::endl;
            break;
        case KEY_PRESSED:
            std::cout << "event: keypressed" << std::endl;
            break;
        case REACHED_HEIGHT:
            std::cout << "event: reachedheight" << std::endl;
            break;
        case PLAYER_USES_BONUS:
            std::cout << "event: bonus" << std::endl;
            break;
        case PLAYER_BOUNCES_ON_PLATFORM:
            std::cout << "event: playerbounces" << std::endl;
            break;
        case PLAYER_DIED:
            std::cout << "event: playerdied" << std::endl;
            break;
    }
}

EventManager& EventManager::getInstance() {
    static EventManager INSTANCE;
    return INSTANCE;
}

EventManager::EventManager() = default;
