//
// Created by robnoo on 26/11/21.
//

#include <stdexcept>
#include "ConcreteFactory.h"
#include "../events/EventManager.h"

std::shared_ptr<controllers::PlatformController>
ConcreteFactory::loadPlatform(PlatformType platformType, BonusType bonus) {
    std::shared_ptr<controllers::PlatformController> platformController;
    if(platformType == PlatformType::STATIC) {
        platformController = std::make_shared<controllers::StaticPlatformController>();
        platformController->load(1);
        std::shared_ptr<EventHandler> handler = platformController;
        EventManager::getInstance().registerHandler(handler);
    } else {
        throw std::runtime_error("Something went wrong");
    }
    return platformController;
}

std::shared_ptr<controllers::PlayerController> ConcreteFactory::loadPlayer() {
    std::shared_ptr<controllers::PlayerController> playerController = std::make_shared<controllers::PlayerController>();
    playerController->load(0.3);
    std::shared_ptr<EventHandler> handler = playerController;
    EventManager::getInstance().registerHandler(handler);
    return playerController;
}
