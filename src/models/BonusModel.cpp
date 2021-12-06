//
// Created by robnoo on 25/11/21.
//

#include "BonusModel.h"
#include "../controllers/PlatformController.h"
#include "../controllers/BonusController.h"

models::JetpackModel::JetpackModel(): BonusModel() {

}

models::SpringModel::SpringModel(): BonusModel() {

}

models::BonusModel::BonusModel(): EntityModel() {

}

void models::BonusModel::update(double elapsed) {
//    auto bonusController = controller.lock();
//    std::shared_ptr<controllers::PlatformController> platform = bonusController.getPl;
//    if(!platform)
//        return;
//    auto box = platform->getBox();
//    double center = (box.second.first + box.first.first)/2;
//    this->moveTo(center, box.first.second);
}
