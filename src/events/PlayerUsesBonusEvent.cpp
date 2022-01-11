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

#include "PlayerUsesBonusEvent.h"

events::PlayerUsesBonusEvent::PlayerUsesBonusEvent(BonusType type, double surfaceHeight, long bonusId): Event(PLAYER_USES_BONUS), bonusType(type), surfaceHeight(surfaceHeight), bonusId(bonusId) {

}

BonusType events::PlayerUsesBonusEvent::getBonusType() {
    return bonusType;
}

double events::PlayerUsesBonusEvent::getSurfaceHeight() const {
    return surfaceHeight;
}

long events::PlayerUsesBonusEvent::getBonusEntityId() const {
    return bonusId;
}
