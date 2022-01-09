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

#ifndef DOODLEJUMP_HEIGHTCHANGEDEVENT_H
#define DOODLEJUMP_HEIGHTCHANGEDEVENT_H


#include "Event.h"

namespace events {

    class HeightChangedEvent : public Event {
    public:
        explicit HeightChangedEvent(double difference);

        [[nodiscard]] double getDifference() const;

    private:
        double difference;

    };

}


#endif //DOODLEJUMP_HEIGHTCHANGEDEVENT_H
