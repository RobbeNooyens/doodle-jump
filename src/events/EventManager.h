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

#ifndef DOODLEJUMP_EVENTMANAGER_H
#define DOODLEJUMP_EVENTMANAGER_H


#include <memory>
#include <vector>

class EventHandler;

namespace events {
    class Event;
}

/**
 * @brief Singleton that manages event handlers and forwards incoming events to handlers
 */
class EventManager {
public:
    /**
     * @brief Registers a handler to make it listen to events
     * @param handler handler to be registered
     */
    void registerHandler(std::shared_ptr<EventHandler> handler);
    /**
     * @brief Unregisters a handler
     * @param id id of the handler to unregister
     */
    void unregisterHandler(unsigned long id);
    /**
     * @brief forwards an incoming event to the handlers
     * @param event event to forward
     */
    void invoke(std::shared_ptr<events::Event> event);

    /**
     * @return singleton instance
     */
    static EventManager& getInstance();
    /**
     * @brief Generates a unique random id as identifier
     * @return generated id
     */
    unsigned long generateId();

    EventManager(EventManager()) = delete;
    void operator=(EventManager const&) = delete;
private:
    EventManager();
    std::vector<std::shared_ptr<EventHandler>> handlers{};
};


#endif //DOODLEJUMP_EVENTMANAGER_H
