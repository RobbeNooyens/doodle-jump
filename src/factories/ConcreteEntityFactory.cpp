//
// Created by robnoo on 26/11/21.
//

#include <stdexcept>
#include "ConcreteEntityFactory.h"
#include "../events/EventManager.h"
#include "../Settings.h"

std::shared_ptr<controllers::PlatformController>
ConcreteEntityFactory::loadPlatform(PlatformType platformType) {
    std::shared_ptr<controllers::PlatformController> platformController;
    if(platformType == PlatformType::STATIC) {
        platformController = std::make_shared<controllers::StaticPlatformController>();
    } else if(platformType == PlatformType::TEMPORARY) {
        platformController = std::make_shared<controllers::TemporaryPlatformController>();
    } else if(platformType == PlatformType::HORIZONTAL) {
        platformController = std::make_shared<controllers::HorizontalPlatformController>();
    } else if(platformType == PlatformType::VERTICAL) {
        platformController = std::make_shared<controllers::VerticalPlatformController>();
    } else {
        throw std::runtime_error("Something went wrong");
    }
    platformController->setSize(60);
    EventManager::getInstance().registerHandler(platformController);
    return platformController;
}

std::shared_ptr<controllers::PlayerController> ConcreteEntityFactory::loadPlayer() {
    std::shared_ptr<controllers::PlayerController> playerController = std::make_shared<controllers::PlayerController>();
    playerController->setSize(60);
    EventManager::getInstance().registerHandler(playerController);
    return playerController;
}

std::shared_ptr<controllers::BonusController> ConcreteEntityFactory::loadBonus(BonusType bonusType) {
    std::shared_ptr<controllers::BonusController> bonusController;
    if(bonusType == BonusType::SPRING) {
        bonusController = std::make_shared<controllers::SpringController>();
    } else if(bonusType == BonusType::JETPACK) {
        bonusController = std::make_shared<controllers::JetpackController>();
    } else {
        throw std::runtime_error("Something went wrong");
    }
    bonusController->setSize(20);
    EventManager::getInstance().registerHandler(bonusController);
    return bonusController;
}

std::shared_ptr<controllers::TileController> ConcreteEntityFactory::loadTile() {
    std::shared_ptr<controllers::TileController> tileController = std::make_shared<controllers::TileController>();
    tileController->setSize(settings::screenWidth);
    EventManager::getInstance().registerHandler(tileController);
    return tileController;
}
