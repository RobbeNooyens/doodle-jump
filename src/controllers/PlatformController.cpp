//
// Created by robnoo on 25/11/21.
//

#include "PlatformController.h"
#include "../events/Event.h"
#include "../events/ReachedNewHeightEvent.h"
#include "../ScoreManager.h"
#include "../events/PlayerBouncesOnPlatformEvent.h"
#include "../models/PlatformModel.h"
#include "../views/PlatformView.h"

controllers::PlatformController::PlatformController(PlatformType type): EntityController(), platformType(type) {
    view = std::make_shared<views::PlatformView>();
}

controllers::StaticPlatformController::StaticPlatformController(): PlatformController(STATIC) {
    model = std::make_shared<models::StaticPlatform>();
//    setTexture("static");
}

controllers::TemporaryPlatformController::TemporaryPlatformController(): PlatformController(TEMPORARY) {
    model = std::make_shared<models::TemporaryPlatform>();
//    setTexture("temporary");
}

controllers::HorizontalPlatformController::HorizontalPlatformController(): PlatformController(HORIZONTAL) {
    model = std::make_shared<models::HorizontalPlatform>();
//    setTexture("horizontal");
}

controllers::VerticalPlatformController::VerticalPlatformController(): PlatformController(VERTICAL) {
    model = std::make_shared<models::VerticalPlatform>();
//    setTexture("vertical");
}

PlatformType controllers::PlatformController::getType() {
    return platformType;
}

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
