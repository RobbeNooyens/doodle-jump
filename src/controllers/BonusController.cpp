//
// Created by robnoo on 25/11/21.
//

#include "BonusController.h"
#include "../models/BonusModel.h"
#include "../views/BonusView.h"

controllers::BonusController::BonusController(): EntityController() {
    view = std::make_shared<views::BonusView>();
}

void controllers::BonusController::update(double elapsed) {

}

void controllers::BonusController::handle(std::shared_ptr<Event> &event) {
}

controllers::SpringController::SpringController(): BonusController() {
    model = std::make_shared<models::SpringModel>();
}

controllers::JetpackController::JetpackController(): BonusController() {
    model = std::make_shared<models::JetpackModel>();
}
