//
// Created by robnoo on 1/12/21.
//

#include "HeightChangedEvent.h"


HeightChangedEvent::HeightChangedEvent(double difference): Event(HEIGHT_CHANGED), difference(difference) {}

double HeightChangedEvent::getDifference() const {
    return difference;
}
