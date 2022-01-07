//
// Created by robnoo on 25/11/21.
//

#include "BonusController.h"
#include "../models/BonusModel.h"
#include "../views/BonusView.h"
#include "../events/ReachedNewHeightEvent.h"
#include "../bounding_box/BoundingBox.h"
#include "../events/PlayerUsesBonusEvent.h"
#include "../controllers/PlatformController.h"

controllers::BonusController::BonusController(BonusType type): EntityController(), bonusType(type) {
    view = std::make_shared<views::BonusView>(shared_from_this());
}

void controllers::BonusController::handle(std::shared_ptr<Event> &event) {
    if(event->getType() == REACHED_HEIGHT) {
        std::shared_ptr<ReachedNewHeightEvent> heightEvent = std::static_pointer_cast<ReachedNewHeightEvent>(event);
        this->changeY(heightEvent->getDifference());
    }

    if(event->getType() == PLAYER_USES_BONUS) {
        std::shared_ptr<PlayerUsesBonusEvent> bonusEvent = std::static_pointer_cast<PlayerUsesBonusEvent>(event);
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

controllers::SpringController::SpringController(): BonusController(SPRING) {
    model = std::make_shared<models::SpringModel>(shared_from_this());
    setTexture("spring");
}

void controllers::SpringController::use() {
    this->setTexture("spring_extended");
}

controllers::JetpackController::JetpackController(): BonusController(JETPACK) {
    model = std::make_shared<models::JetpackModel>(shared_from_this());
    setTexture("jetpack");
}

void controllers::JetpackController::use() {

}
