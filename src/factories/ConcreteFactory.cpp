//
// Created by robnoo on 26/11/21.
//

#include <stdexcept>
#include "ConcreteFactory.h"
#include "../events/EventManager.h"
#include "../Settings.h"

std::shared_ptr<controllers::PlatformController>
ConcreteFactory::loadPlatform(PlatformType platformType) {
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
        platformController = std::make_shared<controllers::HorizontalPlatformController>();
        texture = "horizontal";
    } else if(platformType == PlatformType::VERTICAL) {
        platformController = std::make_shared<controllers::VerticalPlatformController>();
        texture = "vertical";
    } else {
        throw std::runtime_error("Something went wrong");
    }
    std::shared_ptr<Resource> resource = ResourceLoader::getInstance().getResource(entity, texture);
    platformController->load(resource);
    platformController->setSize(60);
    std::shared_ptr<EntityController> controller = platformController;
    platformController->link(controller);
    std::shared_ptr<EventHandler> handler = platformController;
    EventManager::getInstance().registerHandler(handler);
    return platformController;
}

std::shared_ptr<controllers::PlayerController> ConcreteFactory::loadPlayer() {
    std::shared_ptr<controllers::PlayerController> playerController = std::make_shared<controllers::PlayerController>();
    std::string entity = "player";
    std::string texture = "right";
    std::shared_ptr<Resource> resource = ResourceLoader::getInstance().getResource(entity, texture);
    playerController->load(resource);
    playerController->setSize(60);
    std::shared_ptr<EntityController> controller = playerController;
    playerController->link(controller);
    std::shared_ptr<EventHandler> handler = playerController;
    EventManager::getInstance().registerHandler(handler);
    return playerController;
}

std::shared_ptr<controllers::BonusController> ConcreteFactory::loadBonus(BonusType bonusType) {
    std::shared_ptr<controllers::BonusController> bonusController;
    std::string entity = "bonus";
    std::string texture;
    if(bonusType == BonusType::SPRING) {
        bonusController = std::make_shared<controllers::SpringController>();
        texture = "spring";
    } else if(bonusType == BonusType::JETPACK) {
        bonusController = std::make_shared<controllers::JetpackController>();
        texture = "jetpack";
    } else {
        throw std::runtime_error("Something went wrong");
    }
    std::shared_ptr<Resource> resource = ResourceLoader::getInstance().getResource(entity, texture);
    bonusController->load(resource);
    bonusController->setSize(20);
    std::shared_ptr<EntityController> controller = bonusController;
    bonusController->link(controller);
    std::shared_ptr<EventHandler> handler = bonusController;
    EventManager::getInstance().registerHandler(handler);
    return bonusController;
}

std::shared_ptr<controllers::TileController> ConcreteFactory::loadTile() {
    std::shared_ptr<controllers::TileController> tileController = std::make_shared<controllers::TileController>();
    std::string entity = "tile";
    std::string texture = "default";
    std::shared_ptr<Resource> resource = ResourceLoader::getInstance().getResource(entity, texture);
    tileController->setSize(settings::screenWidth);
    tileController->load(resource);
    tileController->setSize(settings::screenWidth);
    std::shared_ptr<EntityController> controller = tileController;
    tileController->link(controller);
    std::shared_ptr<EventHandler> handler = tileController;
    EventManager::getInstance().registerHandler(handler);
    return tileController;
}
