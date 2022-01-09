//
// Created by robnoo on 1/12/21.
//

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
