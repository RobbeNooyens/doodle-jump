//
// Created by robnoo on 23/12/21.
//

#include "PlayerBouncesOnPlatformEvent.h"

events::PlayerBouncesOnPlatformEvent::PlayerBouncesOnPlatformEvent(double surfaceHeight, long platformId): Event(GameEventType::PLAYER_BOUNCES_ON_PLATFORM), platformId(platformId), surfaceHeight(surfaceHeight) {

}

long events::PlayerBouncesOnPlatformEvent::getPlatformId() const {
    return platformId;
}

double events::PlayerBouncesOnPlatformEvent::getSurfaceHeight() {
    return surfaceHeight;
}

