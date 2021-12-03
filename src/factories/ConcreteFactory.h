//
// Created by robnoo on 26/11/21.
//

#ifndef DOODLEJUMP_CONCRETEFACTORY_H
#define DOODLEJUMP_CONCRETEFACTORY_H


#include "AbstractFactory.h"

class ConcreteFactory: public AbstractFactory {
public:
    std::shared_ptr<controllers::PlatformController> loadPlatform(PlatformType platformType) override;
    std::shared_ptr<controllers::PlayerController> loadPlayer() override;

    std::shared_ptr<controllers::BonusController> loadBonus(BonusType bonusType) override;

};


#endif //DOODLEJUMP_CONCRETEFACTORY_H
