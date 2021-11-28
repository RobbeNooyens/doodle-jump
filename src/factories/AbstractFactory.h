//
// Created by robnoo on 26/11/21.
//

#ifndef DOODLEJUMP_ABSTRACTFACTORY_H
#define DOODLEJUMP_ABSTRACTFACTORY_H


#include "../controllers/Platform.h"
#include "../controllers/PlayerController.h"

enum PlatformType { STATIC, HORIZONTAL, VERTICAL, TEMPORARY };
enum BonusType { NONE, SPRING, JETPACK };

class AbstractFactory {
public:
    virtual controllers::Platform loadPlatform(PlatformType platformType, BonusType bonus) = 0;
    controllers::Platform loadPlatform(PlatformType platformType) {
        return loadPlatform(platformType, BonusType::NONE);
    }

    virtual controllers::PlayerController loadPlayer() = 0;
};


#endif //DOODLEJUMP_ABSTRACTFACTORY_H
