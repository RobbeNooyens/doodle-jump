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
        std::string entity = "platform";
        std::string texture = "static";
        std::shared_ptr<Resource> resource = ResourceLoader::getInstance().getResource(entity, texture);
        platformController->load(resource);
        platformController->setSize(60);
        std::shared_ptr<EventHandler> handler = platformController;
        EventManager::getInstance().registerHandler(handler);
    } else {
        throw std::runtime_error("Something went wrong");
    }
    return platformController;
}

std::shared_ptr<controllers::PlayerController> ConcreteFactory::loadPlayer() {
    std::shared_ptr<controllers::PlayerController> playerController = std::make_shared<controllers::PlayerController>();
    std::string entity = "player";
    std::string texture = "left";
    std::shared_ptr<Resource> resource = ResourceLoader::getInstance().getResource(entity, texture);
    playerController->load(resource);
    playerController->setSize(60);
    std::shared_ptr<EventHandler> handler = playerController;
    EventManager::getInstance().registerHandler(handler);
    return playerController;
}
