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

    /**
     * @brief Represents an event when a player collides with a platform and jumps off
     */
    class PlayerBouncesOnPlatformEvent : public Event {
    public:
        /**
         * @brief Parameter constructor
         * @param surfaceHeight y value of the platform top
         * @param platformId id of the platform the player jumped on
         */
        explicit PlayerBouncesOnPlatformEvent(double surfaceHeight, long platformId);

        /**
         * @return id of platform the player jumped on
         */
        [[nodiscard]] long getPlatformId() const;

        /**
         * @return y value of platform top
         */
        double getSurfaceHeight();

    private:
        double surfaceHeight;
        long platformId;

    };

}

#endif //DOODLEJUMP_PLAYERBOUNCESONPLATFORMEVENT_H
