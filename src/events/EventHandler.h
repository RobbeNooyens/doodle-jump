//
// Created by robnoo on 28/11/21.
//

#ifndef DOODLEJUMP_EVENTHANDLER_H
#define DOODLEJUMP_EVENTHANDLER_H

#include <memory>

class Event;

class EventHandler {
public:
    EventHandler();
    virtual ~EventHandler();

    virtual void handle(std::shared_ptr<Event>& event) = 0;

    void unregister() const;

    [[nodiscard]] unsigned long getHandlerId() const;

private:
    unsigned long id;
};

#endif //DOODLEJUMP_EVENTHANDLER_H
