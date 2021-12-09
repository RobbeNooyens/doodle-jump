//
// Created by robnoo on 1/12/21.
//

#include "ReachedNewHeightEvent.h"


ReachedNewHeightEvent::ReachedNewHeightEvent(double difference, double maxHeight): Event(REACHED_HEIGHT), difference(difference), maxHeight(maxHeight) {

}

double ReachedNewHeightEvent::getDifference() {
    return difference;
}

double ReachedNewHeightEvent::getMaxHeight() {
    return maxHeight;
}
