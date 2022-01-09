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

#ifndef DOODLEJUMP_PLAYERUSESBONUSEVENT_H
#define DOODLEJUMP_PLAYERUSESBONUSEVENT_H


#include "Event.h"
#include "../enums/BonusType.h"

namespace events {

    class PlayerUsesBonusEvent : public Event {
    public:
        PlayerUsesBonusEvent(BonusType type, double surfaceHeight, long bonusId);

        BonusType getBonusType();

        double getSurfaceHeight();

        long getBonusEntityId();

    private:
        BonusType bonusType;
        double surfaceHeight;
        long bonusId;

    };

}


#endif //DOODLEJUMP_PLAYERUSESBONUSEVENT_H
