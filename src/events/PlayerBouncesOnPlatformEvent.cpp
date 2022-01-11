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

#include "PlayerBouncesOnPlatformEvent.h"

events::PlayerBouncesOnPlatformEvent::PlayerBouncesOnPlatformEvent(double surfaceHeight, long platformId): Event(GameEventType::PLAYER_BOUNCES_ON_PLATFORM), platformId(platformId), surfaceHeight(surfaceHeight) {

}

long events::PlayerBouncesOnPlatformEvent::getPlatformId() const {
    return platformId;
}

double events::PlayerBouncesOnPlatformEvent::getSurfaceHeight() const {
    return surfaceHeight;
}

