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

#ifndef DOODLEJUMP_EVENTHANDLER_H
#define DOODLEJUMP_EVENTHANDLER_H

#include <memory>

namespace events {
    class Event;
}

/**
 * @brief Abstract representation of object that can handle incoming events
 */
class EventHandler {
public:
    /**
     * @brief Default constructor
     */
    EventHandler();
    /**
     * @brief Default virtual destructor
     */
    virtual ~EventHandler();

    /**
     * @brief Handles incoming game events
     * @param event event that got invoked
     */
    virtual void handle(std::shared_ptr<events::Event> &event) = 0;
    /**
     * @brief Unregisters itself from the EventManager
     */
    void unregister() const;

    /**
     * @return handler id
     */
    [[nodiscard]] unsigned long getHandlerId() const;

private:
    unsigned long id = 0;
};

#endif //DOODLEJUMP_EVENTHANDLER_H
