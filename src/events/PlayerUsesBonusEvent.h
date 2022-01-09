//
// Created by robnoo on 21/12/21.
//

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
