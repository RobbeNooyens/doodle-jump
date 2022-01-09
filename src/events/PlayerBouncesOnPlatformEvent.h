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

#ifndef DOODLEJUMP_PLAYERBOUNCESONPLATFORMEVENT_H
#define DOODLEJUMP_PLAYERBOUNCESONPLATFORMEVENT_H


#include "Event.h"

namespace events {

    class PlayerBouncesOnPlatformEvent : public Event {
    public:
        explicit PlayerBouncesOnPlatformEvent(double surfaceHeight, long platformId);

        [[nodiscard]] long getPlatformId() const;

        double getSurfaceHeight();

    private:
        double surfaceHeight;
        long platformId;

    };

}

#endif //DOODLEJUMP_PLAYERBOUNCESONPLATFORMEVENT_H
