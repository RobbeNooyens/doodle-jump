//
// Created by robnoo on 26/11/21.
//

#include <stdexcept>
#include "ConcreteFactory.h"
#include "../events/EventManager.h"

std::shared_ptr<controllers::PlatformController>
ConcreteFactory::loadPlatform(PlatformType platformType, BonusType bonus) {
    std::shared_ptr<controllers::PlatformController> platformController;
    std::string entity = "platform";
    std::string texture;
    if(platformType == PlatformType::STATIC) {
        platformController = std::make_shared<controllers::StaticPlatformController>();
        texture = "static";
    } else if(platformType == PlatformType::TEMPORARY) {
        platformController = std::make_shared<controllers::TemporaryPlatformController>();
        texture = "temporary";
    } else if(platformType == PlatformType::HORIZONTAL) {
        platformController = std::make_shared<controllers::TemporaryPlatformController>();
        texture = "horizontal";
    } else if(platformType == PlatformType::VERTICAL) {
        platformController = std::make_shared<controllers::TemporaryPlatformController>();
        texture = "vertical";
    } else {
        throw std::runtime_error("Something went wrong");
    }
    std::shared_ptr<Resource> resource = ResourceLoader::getInstance().getResource(entity, texture);
    platformController->load(resource);
    platformController->setSize(60);
    std::shared_ptr<EventHandler> handler = platformController;
    EventManager::getInstance().registerHandler(handler);
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
