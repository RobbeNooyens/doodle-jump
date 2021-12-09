//
// Created by robnoo on 1/12/21.
//

#ifndef DOODLEJUMP_REACHEDNEWHEIGHTEVENT_H
#define DOODLEJUMP_REACHEDNEWHEIGHTEVENT_H


#include "Event.h"

class ReachedNewHeightEvent: public Event {
public:
    ReachedNewHeightEvent(double difference, double maxHeight);

    double getDifference();
    double getMaxHeight();

private:
    double difference;
    double maxHeight;

};


#endif //DOODLEJUMP_REACHEDNEWHEIGHTEVENT_H
