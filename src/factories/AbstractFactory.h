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
    virtual controllers::PlatformController loadPlatform(PlatformType platformType, BonusType bonus) = 0;
    controllers::PlatformController loadPlatform(PlatformType platformType) {
        return loadPlatform(platformType, BonusType::NONE);
    }

    virtual controllers::PlayerController loadPlayer() = 0;
};


#endif //DOODLEJUMP_ABSTRACTFACTORY_H
