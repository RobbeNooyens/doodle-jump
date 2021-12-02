//
// Created by robnoo on 26/11/21.
//

#ifndef DOODLEJUMP_ABSTRACTFACTORY_H
#define DOODLEJUMP_ABSTRACTFACTORY_H


#include "../controllers/PlatformController.h"
#include "../controllers/PlayerController.h"

enum PlatformType { STATIC, HORIZONTAL, VERTICAL, TEMPORARY };
enum BonusType { NONE, SPRING, JETPACK };

class AbstractFactory {
public:
    virtual std::shared_ptr<controllers::PlatformController> loadPlatform(PlatformType platformType, BonusType bonus) = 0;
    std::shared_ptr<controllers::PlatformController> loadPlatform(PlatformType platformType) {
        return loadPlatform(platformType, BonusType::NONE);
    }

    virtual std::shared_ptr<controllers::PlayerController> loadPlayer() = 0;
};


#endif //DOODLEJUMP_ABSTRACTFACTORY_H
