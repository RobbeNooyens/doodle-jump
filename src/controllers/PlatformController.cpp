//
// Created by robnoo on 25/11/21.
//

#include "PlatformController.h"
#include "../utils/TextureLoader.h"
#include "../events/Event.h"
#include "../events/ReachedNewHeightEvent.h"
#include "../ScoreManager.h"
#include "../events/PlayerBouncesOnPlatformEvent.h"

void controllers::PlatformController::handle(std::shared_ptr<Event> &event) {
    if(event->getType() == REACHED_HEIGHT) {
        auto heightEvent = std::static_pointer_cast<ReachedNewHeightEvent>(event);
        this->changeY(heightEvent->getDifference());
    }

    if(event->getType() == PLAYER_BOUNCES_ON_PLATFORM) {
        auto bounceEvent = std::static_pointer_cast<PlayerBouncesOnPlatformEvent>(event);
        if(bounceEvent->getPlatformId() == getId()) {
            jumpCount++;
            if(jumpCount > 1) {
                ScoreManager::getInstance().addScore(-jumpCount*50);
            }
            if(getType() == TEMPORARY) {
                destroy();
            }
        }
    }
}

controllers::PlatformController::PlatformController(): EntityController(EntityType::PLATFORM) {
    view = std::make_shared<views::PlatformView>();
}

controllers::StaticPlatformController::StaticPlatformController(): PlatformController() {
    model = std::make_shared<models::StaticPlatform>();
}

PlatformType controllers::StaticPlatformController::getType() {
    return STATIC;
}

controllers::TemporaryPlatformController::TemporaryPlatformController(): PlatformController() {
    model = std::make_shared<models::TemporaryPlatform>();
}

PlatformType controllers::TemporaryPlatformController::getType() {
    return TEMPORARY;
}

controllers::HorizontalPlatformController::HorizontalPlatformController(): PlatformController() {
    model = std::make_shared<models::HorizontalPlatform>();
}

PlatformType controllers::HorizontalPlatformController::getType() {
    return HORIZONTAL;
}

controllers::VerticalPlatformController::VerticalPlatformController(): PlatformController() {
    model = std::make_shared<models::VerticalPlatform>();
}

PlatformType controllers::VerticalPlatformController::getType() {
    return VERTICAL;
}
