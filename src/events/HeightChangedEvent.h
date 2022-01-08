//
// Created by robnoo on 1/12/21.
//

#ifndef DOODLEJUMP_HEIGHTCHANGEDEVENT_H
#define DOODLEJUMP_HEIGHTCHANGEDEVENT_H


#include "Event.h"

class HeightChangedEvent: public Event {
public:
    HeightChangedEvent(double difference, double maxHeight);

    double getDifference();
    double getMaxHeight();

private:
    double difference;
    double maxHeight;

};


#endif //DOODLEJUMP_HEIGHTCHANGEDEVENT_H
