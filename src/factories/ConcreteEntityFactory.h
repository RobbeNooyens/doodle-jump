//
// Created by robnoo on 26/11/21.
//

#ifndef DOODLEJUMP_CONCRETEENTITYFACTORY_H
#define DOODLEJUMP_CONCRETEENTITYFACTORY_H


#include "EntityFactory.h"

class ConcreteEntityFactory: public EntityFactory {
public:
    std::shared_ptr<controllers::PlatformController> loadPlatform(PlatformType platformType) override;
    std::shared_ptr<controllers::PlayerController> loadPlayer() override;

    std::shared_ptr<controllers::BonusController> loadBonus(BonusType bonusType) override;

    std::shared_ptr<controllers::TileController> loadTile() override;

};


#endif //DOODLEJUMP_CONCRETEENTITYFACTORY_H
