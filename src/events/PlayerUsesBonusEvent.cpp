//
// Created by robnoo on 21/12/21.
//

#include "PlayerUsesBonusEvent.h"

PlayerUsesBonusEvent::PlayerUsesBonusEvent(BonusType type): Event(PLAYER_USES_BONUS), bonusType(type) {

}

BonusType PlayerUsesBonusEvent::getBonusType() {
    return bonusType;
}
