//
// Created by robnoo on 21/12/21.
//

#include "PlayerUsesBonusEvent.h"

events::PlayerUsesBonusEvent::PlayerUsesBonusEvent(BonusType type, double surfaceHeight, long bonusId): Event(PLAYER_USES_BONUS), bonusType(type), surfaceHeight(surfaceHeight), bonusId(bonusId) {

}

BonusType events::PlayerUsesBonusEvent::getBonusType() {
    return bonusType;
}

double events::PlayerUsesBonusEvent::getSurfaceHeight() {
    return surfaceHeight;
}

long events::PlayerUsesBonusEvent::getBonusEntityId() {
    return bonusId;
}
