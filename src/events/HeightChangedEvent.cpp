//
// Created by robnoo on 1/12/21.
//

#include "HeightChangedEvent.h"


events::HeightChangedEvent::HeightChangedEvent(double difference): Event(HEIGHT_CHANGED), difference(difference) {}

double events::HeightChangedEvent::getDifference() const {
    return difference;
}
