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

    /**
     * @brief Represents an event invoked when the camera height changes
     */
    class HeightChangedEvent : public Event {
    public:
        /**
         * @brief Parameter constructor
         * @param difference distance added
         */
        explicit HeightChangedEvent(double difference);

        /**
         * @return the distance that was added
         */
        [[nodiscard]] double getDifference() const;

    private:
        double difference;

    };

}


#endif //DOODLEJUMP_HEIGHTCHANGEDEVENT_H
