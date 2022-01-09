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

class EventHandler {
public:
    EventHandler();
    virtual ~EventHandler();

    virtual void handle(std::shared_ptr<events::Event> &event) = 0;

    void unregister() const;

    [[nodiscard]] unsigned long getHandlerId() const;

private:
    unsigned long id;
};

#endif //DOODLEJUMP_EVENTHANDLER_H
