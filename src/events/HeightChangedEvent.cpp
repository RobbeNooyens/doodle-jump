//
// Created by robnoo on 1/12/21.
//

#include "HeightChangedEvent.h"


HeightChangedEvent::HeightChangedEvent(double difference, double maxHeight): Event(HEIGHT_CHANGED), difference(difference), maxHeight(maxHeight) {

}

double HeightChangedEvent::getDifference() {
    return difference;
}

double HeightChangedEvent::getMaxHeight() {
    return maxHeight;
}
