//
// Created by robnoo on 25/11/21.
//

#include "BonusController.h"
#include "../models/BonusModel.h"
#include "../views/BonusView.h"
#include "../utils/ResourceLoader.h"

controllers::BonusController::BonusController(): EntityController() {
    view = std::make_shared<views::BonusView>();
}

void controllers::BonusController::handle(std::shared_ptr<Event> &event) {
}

controllers::SpringController::SpringController(): BonusController() {
    model = std::make_shared<models::SpringModel>();
}

void controllers::SpringController::use() {
    std::string entity = "bonus";
    std::string texture = "spring_extended";
    std::shared_ptr<Resource> extended_spring = ResourceLoader::getInstance().getResource(entity, texture);
    this->load(extended_spring);
}

controllers::JetpackController::JetpackController(): BonusController() {
    model = std::make_shared<models::JetpackModel>();
}

void controllers::JetpackController::use() {

}
