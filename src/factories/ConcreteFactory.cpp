//
// Created by robnoo on 26/11/21.
//

#include "ConcreteFactory.h"

std::shared_ptr<controllers::PlatformController>
ConcreteFactory::loadPlatform(PlatformType platformType, BonusType bonus) {
    std::shared_ptr<controllers::PlatformController> platformController;
    switch (platformType) {
        case STATIC:
            platformController = std::make_shared<controllers::StaticPlatformController>();
            break;
        case HORIZONTAL:
            break;
        case VERTICAL:
            break;
        case TEMPORARY:
            break;
    }
    return platformController;
}

std::shared_ptr<controllers::PlayerController> ConcreteFactory::loadPlayer() {
    std::shared_ptr<controllers::PlayerController> playerController = std::make_shared<controllers::PlayerController>();
    playerController->load(0.3);
    return playerController;
}
