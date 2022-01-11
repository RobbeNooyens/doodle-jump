/**
 *  ╒══════════════════════════════════════╕
 *  │                                      │
 *  │             Doodle Jump              │
 *  │        Advanced Programming          │
 *  │                                      │
 *  │            Robbe Nooyens             │
 *  │    s0201010@student.uantwerpen.be    │
 *  │                                      │
 *  │        University of Antwerp         │
 *  │                                      │
 *  ╘══════════════════════════════════════╛
 */

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
