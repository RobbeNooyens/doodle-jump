//
// Created by robnoo on 25/11/21.
//

#include "BonusController.h"
#include "../models/BonusModel.h"
#include "../views/BonusView.h"
#include "../utils/ResourceLoader.h"
#include "../events/ReachedNewHeightEvent.h"
#include "../bounding_box/BoundingBox.h"
#include "../events/PlayerUsesBonusEvent.h"

controllers::BonusController::BonusController(): EntityController(EntityType::BONUS) {
    view = std::make_shared<views::BonusView>();
}

void controllers::BonusController::handle(std::shared_ptr<Event> &event) {
    if(event->getType() == REACHED_HEIGHT) {
        std::shared_ptr<ReachedNewHeightEvent> heightEvent = std::static_pointer_cast<ReachedNewHeightEvent>(event);
        this->changeY(heightEvent->getDifference());
    }

    if(event->getType() == PLAYER_USES_BONUS) {
        std::shared_ptr<PlayerUsesBonusEvent> bonusEvent = std::static_pointer_cast<PlayerUsesBonusEvent>(event);
        if(bonusEvent->getBonusEntityId() == getId()) {
            if(getType() == SPRING) {
                std::string entity = "bonus";
                std::string texture = "spring_extended";
                std::shared_ptr<Resource> extended_spring = ResourceLoader::getInstance().getResource(entity, texture);
                this->load(extended_spring);
            }
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
        this->moveTo(platformBox->getCenter().first + offset, platformBox->getTop());
    } else {
        this->destroy();
    }
}

void controllers::BonusController::setPlatform(std::shared_ptr<PlatformController> &platformController) {
    this->platform = platformController;
    auto platformBox = platform->getBoundingBox();
    this->moveTo(platformBox->getCenter().first + offset, platformBox->getTop());
}

BonusType controllers::BonusController::getType() {
    return bonusType;
}

controllers::SpringController::SpringController(): BonusController() {
    model = std::make_shared<models::SpringModel>();
    bonusType = SPRING;
}

controllers::JetpackController::JetpackController(): BonusController() {
    model = std::make_shared<models::JetpackModel>();
    bonusType = JETPACK;
}
