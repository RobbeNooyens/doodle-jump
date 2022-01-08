//
// Created by robnoo on 21/12/21.
//

#include "PlayerUsesBonusEvent.h"

PlayerUsesBonusEvent::PlayerUsesBonusEvent(BonusType type, double surfaceHeight, long bonusId): Event(PLAYER_USES_BONUS), bonusType(type), surfaceHeight(surfaceHeight), bonusId(bonusId) {

}

BonusType PlayerUsesBonusEvent::getBonusType() {
    return bonusType;
}

double PlayerUsesBonusEvent::getSurfaceHeight() {
    return surfaceHeight;
}

long PlayerUsesBonusEvent::getBonusEntityId() {
    return bonusId;
}
