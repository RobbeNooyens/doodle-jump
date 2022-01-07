//
// Created by robnoo on 25/11/21.
//

#include "BonusModel.h"
#include "../controllers/PlatformController.h"

models::JetpackModel::JetpackModel(std::shared_ptr<EntityController> controller): BonusModel(controller) {

}

models::SpringModel::SpringModel(std::shared_ptr<EntityController> controller): BonusModel(controller) {

}

models::BonusModel::BonusModel(std::shared_ptr<EntityController>& controller): EntityModel(controller) {

}

void models::BonusModel::update(double elapsed) {
}
