//
// Created by robnoo on 26/11/21.
//

#ifndef DOODLEJUMP_ENTITYFACTORY_H
#define DOODLEJUMP_ENTITYFACTORY_H


#include "../controllers/PlatformController.h"
#include "../controllers/PlayerController.h"
#include "../controllers/BonusController.h"
#include "../controllers/TileController.h"
#include "../enums/PlatformType.h"
#include "../controllers/TextController.h"

class EntityFactory {
public:
    virtual std::shared_ptr<controllers::PlatformController> loadPlatform(PlatformType platformType) = 0;
    virtual std::shared_ptr<controllers::PlayerController> loadPlayer() = 0;
    virtual std::shared_ptr<controllers::BonusController> loadBonus(BonusType bonusType) = 0;
    virtual std::shared_ptr<controllers::TileController> loadTile() = 0;
    virtual std::shared_ptr<controllers::TextController> loadText(std::basic_string<char> text, unsigned int fontSize) = 0;
};


#endif //DOODLEJUMP_ENTITYFACTORY_H
