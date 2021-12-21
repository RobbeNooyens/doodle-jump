//
// Created by robnoo on 21/12/21.
//

#ifndef DOODLEJUMP_PLAYERUSESBONUSEVENT_H
#define DOODLEJUMP_PLAYERUSESBONUSEVENT_H


#include "Event.h"
#include "../enums/BonusType.h"

class PlayerUsesBonusEvent: public Event {
public:
    PlayerUsesBonusEvent(BonusType type);
    BonusType getBonusType();

private:
    BonusType bonusType;

};


#endif //DOODLEJUMP_PLAYERUSESBONUSEVENT_H
