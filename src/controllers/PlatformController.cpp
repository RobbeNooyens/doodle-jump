//
// Created by robnoo on 25/11/21.
//

#include "PlatformController.h"
#include "../utils/ResourceLoader.h"
#include "../events/Event.h"
#include "../events/ReachedNewHeightEvent.h"
#include "../ScoreManager.h"

void controllers::PlatformController::handle(std::shared_ptr<Event> &event) {
    if(event->getType() == REACHED_HEIGHT) {
        std::shared_ptr<ReachedNewHeightEvent> heightEvent = std::static_pointer_cast<ReachedNewHeightEvent>(event);
        this->changeY(heightEvent->getDifference());
    }
}

controllers::PlatformController::PlatformController(): EntityController(EntityType::PLATFORM) {
    view = std::make_shared<views::PlatformView>();
}

void controllers::PlatformController::increaseJumpCount() {
    jumpCount++;
    if(jumpCount > 1) {
        ScoreManager::getInstance().addScore(-jumpCount*50);
    }
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
