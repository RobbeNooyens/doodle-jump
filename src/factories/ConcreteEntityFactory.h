//
// Created by robnoo on 26/11/21.
//

#ifndef DOODLEJUMP_CONCRETEENTITYFACTORY_H
#define DOODLEJUMP_CONCRETEENTITYFACTORY_H

#include "EntityFactory.h"

class WrapperFactory;

class ConcreteEntityFactory: public EntityFactory {
public:
    explicit ConcreteEntityFactory(std::shared_ptr<WrapperFactory>& wrapperFactory);
    std::shared_ptr<controllers::PlatformController> loadPlatform(PlatformType platformType) override;
    std::shared_ptr<controllers::PlayerController> loadPlayer() override;
    std::shared_ptr<controllers::BonusController> loadBonus(BonusType bonusType) override;
    std::shared_ptr<controllers::TileController> loadTile() override;
    std::shared_ptr<controllers::TextController> loadText(std::basic_string<char> text, unsigned int size) override;

private:
    std::shared_ptr<WrapperFactory> wrapperFactory;

};


#endif //DOODLEJUMP_CONCRETEENTITYFACTORY_H
