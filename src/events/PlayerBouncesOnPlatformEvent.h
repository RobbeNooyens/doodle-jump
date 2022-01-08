//
// Created by robnoo on 23/12/21.
//

#ifndef DOODLEJUMP_PLAYERBOUNCESONPLATFORMEVENT_H
#define DOODLEJUMP_PLAYERBOUNCESONPLATFORMEVENT_H


#include "Event.h"

class PlayerBouncesOnPlatformEvent: public Event {
public:
    explicit PlayerBouncesOnPlatformEvent(double surfaceHeight, long platformId);
    [[nodiscard]] long getPlatformId() const;
    double getSurfaceHeight();

private:
    double surfaceHeight;
    long platformId;

};


#endif //DOODLEJUMP_PLAYERBOUNCESONPLATFORMEVENT_H
