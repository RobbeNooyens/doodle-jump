//
// Created by robnoo on 26/11/21.
//

#ifndef DOODLEJUMP_ABSTRACTFACTORY_H
#define DOODLEJUMP_ABSTRACTFACTORY_H


#include "../controllers/PlatformController.h"
#include "../controllers/PlayerController.h"
#include "../controllers/BonusController.h"
#include "../controllers/TileController.h"

enum PlatformType { STATIC, HORIZONTAL, VERTICAL, TEMPORARY };
enum BonusType { SPRING, JETPACK };

class AbstractFactory {
public:
    virtual std::shared_ptr<controllers::PlatformController> loadPlatform(PlatformType platformType) = 0;
    virtual std::shared_ptr<controllers::PlayerController> loadPlayer() = 0;
    virtual std::shared_ptr<controllers::BonusController> loadBonus(BonusType bonusType) = 0;
    virtual std::shared_ptr<controllers::TileController> loadTile() = 0;
};


#endif //DOODLEJUMP_ABSTRACTFACTORY_H
