//
// Created by robnoo on 25/11/21.
//

#include "BonusController.h"
#include "../models/BonusModel.h"
#include "../views/BonusView.h"
#include "../utils/ResourceLoader.h"
#include "../events/ReachedNewHeightEvent.h"

controllers::BonusController::BonusController(): EntityController(EntityType::BONUS) {
    view = std::make_shared<views::BonusView>();
}

void controllers::BonusController::handle(std::shared_ptr<Event> &event) {
    if(event->getType() == REACHED_HEIGHT) {
        std::shared_ptr<ReachedNewHeightEvent> heightEvent = std::static_pointer_cast<ReachedNewHeightEvent>(event);
        this->changeY(heightEvent->getDifference());
    }
}

void controllers::BonusController::update(double elapsed) {
    EntityController::update(elapsed);
    if(platform) {
        if(platform->isDestroyed()) {
            this->destroy();
            return;
        }
        AbsoluteBoundingBox platformBox = platform->getCollisionBox();
        this->moveTo(platformBox.getRelativeCenter().first + platformBox.upperLeft.first + offset, platformBox.upperLeft.second);
    } else {
        this->destroy();
    }
}

void controllers::BonusController::setPlatform(std::shared_ptr<PlatformController> &platformController) {
    this->platform = platformController;
}

BonusType controllers::BonusController::getType() {
    return bonusType;
}

controllers::SpringController::SpringController(): BonusController() {
    model = std::make_shared<models::SpringModel>();
    bonusType = SPRING;
}

void controllers::SpringController::use() {
    std::string entity = "bonus";
    std::string texture = "spring_extended";
    std::shared_ptr<Resource> extended_spring = ResourceLoader::getInstance().getResource(entity, texture);
    this->load(extended_spring);
}

controllers::JetpackController::JetpackController(): BonusController() {
    model = std::make_shared<models::JetpackModel>();
    bonusType = JETPACK;
}

void controllers::JetpackController::use() {

}
