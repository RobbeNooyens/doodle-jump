/**
 *  ╒══════════════════════════════════════╕
 *  │                                      │
 *  │             Doodle Jump              │
 *  │        Advanced Programming          │
 *  │                                      │
 *  │            Robbe Nooyens             │
 *  │    s0201010@student.uantwerpen.be    │
 *  │                                      │
 *  │        University of Antwerp         │
 *  │                                      │
 *  ╘══════════════════════════════════════╛
 */

#include "ConcreteEntityFactory.h"
#include "../events/EventManager.h"
#include "../wrappers/WrapperFactory.h"
#include "../controllers/PlatformController.h"
#include "../controllers/PlayerController.h"
#include "../controllers/BonusController.h"
#include "../controllers/TileController.h"
#include "../controllers/TextController.h"
#include "../Settings.h"

std::shared_ptr<controllers::PlatformController>
ConcreteEntityFactory::loadPlatform(PlatformType platformType) {
    std::shared_ptr<controllers::PlatformController> platformController;
    std::shared_ptr<wrappers::SpriteWrapper> platformSprite = wrapperFactory->createSprite();
    if(platformType == PlatformType::STATIC) {
        platformController = std::make_shared<controllers::StaticPlatformController>();
        platformController->setSprite(platformSprite);
        platformController->setTexture("static");
    } else if(platformType == PlatformType::TEMPORARY) {
        platformController = std::make_shared<controllers::TemporaryPlatformController>();
        platformController->setSprite(platformSprite);
        platformController->setTexture("temporary");
    } else if(platformType == PlatformType::HORIZONTAL) {
        platformController = std::make_shared<controllers::HorizontalPlatformController>();
        platformController->setSprite(platformSprite);
        platformController->setTexture("horizontal");
    } else if(platformType == PlatformType::VERTICAL) {
        platformController = std::make_shared<controllers::VerticalPlatformController>();
        platformController->setSprite(platformSprite);
        platformController->setTexture("vertical");
    }
    platformController->setSize(settings::platformSize);
    EventManager::getInstance().registerHandler(platformController);
    return platformController;
}

std::shared_ptr<controllers::PlayerController> ConcreteEntityFactory::loadPlayer() {
    std::shared_ptr<controllers::PlayerController> playerController = std::make_shared<controllers::PlayerController>();
    playerController->setSprite(wrapperFactory->createSprite());
    playerController->setSize(settings::playerSize);
    playerController->setTexture("left");
    EventManager::getInstance().registerHandler(playerController);
    return playerController;
}

std::shared_ptr<controllers::BonusController> ConcreteEntityFactory::loadBonus(BonusType bonusType) {
    std::shared_ptr<controllers::BonusController> bonusController;
    auto bonusSprite = wrapperFactory->createSprite();
    if(bonusType == BonusType::SPRING) {
        bonusController = std::make_shared<controllers::SpringController>();
        bonusController->setSprite(bonusSprite);
        bonusController->setTexture("spring");
    } else if(bonusType == BonusType::JETPACK) {
        bonusController = std::make_shared<controllers::JetpackController>();
        bonusController->setSprite(bonusSprite);
        bonusController->setTexture("jetpack");
    }
    bonusController->setSize(settings::bonusSize);
    EventManager::getInstance().registerHandler(bonusController);
    return bonusController;
}

std::shared_ptr<controllers::TileController> ConcreteEntityFactory::loadTile() {
    std::shared_ptr<controllers::TileController> tileController = std::make_shared<controllers::TileController>();
    tileController->setSprite(wrapperFactory->createSprite());
    tileController->setSize(settings::screenWidth);
    tileController->setTexture("default");
    EventManager::getInstance().registerHandler(tileController);
    return tileController;
}

ConcreteEntityFactory::ConcreteEntityFactory(std::shared_ptr<wrappers::WrapperFactory>& wrapperFactory) {
    this->wrapperFactory = wrapperFactory;
}

std::shared_ptr<controllers::TextController> ConcreteEntityFactory::loadText(std::basic_string<char> text, unsigned int size) {
    auto textWrapper = wrapperFactory->createText(text, size);
    auto textController = std::make_shared<controllers::TextController>();
    textController->setTextWrapper(textWrapper);
    return textController;
}
