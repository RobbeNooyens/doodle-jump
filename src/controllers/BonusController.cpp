//
// Created by robnoo on 25/11/21.
//

#include "BonusController.h"
#include "../models/BonusModel.h"
#include "../views/BonusView.h"
#include "../events/HeightChangedEvent.h"
#include "../bounding_box/BoundingBox.h"
#include "../events/PlayerUsesBonusEvent.h"
#include "../controllers/PlatformController.h"

controllers::BonusController::BonusController(BonusType type): EntityController(), bonusType(type) {
    view = std::make_shared<views::BonusView>();
}

void controllers::BonusController::handle(std::shared_ptr<events::Event> &event) {
    if(event->getType() == HEIGHT_CHANGED) {
        std::shared_ptr<events::HeightChangedEvent> heightEvent = std::static_pointer_cast<events::HeightChangedEvent>(event);
        this->changeY(heightEvent->getDifference());
    }

    if(event->getType() == PLAYER_USES_BONUS) {
        std::shared_ptr<events::PlayerUsesBonusEvent> bonusEvent = std::static_pointer_cast<events::PlayerUsesBonusEvent>(event);
        if(bonusEvent->getBonusEntityId() == getId()) {
            this->use();
        }
    }
}

void controllers::BonusController::update(double elapsed) {
    EntityController::update(elapsed);
    if(platform) {
        if(platform->isDestroyed()) {
            this->destroy();
            return;
        }
        auto platformBox = platform->getBoundingBox();
        this->setPosition(platformBox->getCenter().first + offset, platformBox->getTop());
    } else {
        this->destroy();
    }
}

void controllers::BonusController::setPlatform(std::shared_ptr<PlatformController> &platformController) {
    this->platform = platformController;
    auto platformBox = platform->getBoundingBox();
    this->setPosition(platformBox->getCenter().first + offset, platformBox->getTop());
}

BonusType controllers::BonusController::getType() {
    return bonusType;
}

void controllers::BonusController::goesBeneathScreen() {
    if(platform->isBeneathScreen()) {
        destroy();
    }
}

controllers::SpringController::SpringController(): BonusController(SPRING) {
    model = std::make_shared<models::SpringModel>();
}

void controllers::SpringController::use() {
    this->setTexture("spring_extended");
}

controllers::JetpackController::JetpackController(): BonusController(JETPACK) {
    model = std::make_shared<models::JetpackModel>();
}

void controllers::JetpackController::use() {

}
