//
// Created by robnoo on 7/01/22.
//
#include "EventHandler.h"
#include "EventManager.h"

EventHandler::EventHandler(): id(EventManager::getInstance().generateId()) {

}

unsigned long EventHandler::getHandlerId() const {
    return id;
}

EventHandler::~EventHandler() {
    unregister();
}

void EventHandler::unregister() const {
    EventManager::getInstance().unregisterHandler(id);
}
