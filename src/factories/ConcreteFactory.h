//
// Created by robnoo on 26/11/21.
//

#ifndef DOODLEJUMP_CONCRETEFACTORY_H
#define DOODLEJUMP_CONCRETEFACTORY_H


#include "AbstractFactory.h"

class ConcreteFactory: public AbstractFactory {
public:
    std::shared_ptr<controllers::PlatformController> loadPlatform(PlatformType platformType, BonusType bonus) override;

    std::shared_ptr<controllers::PlayerController> loadPlayer() override;

};


#endif //DOODLEJUMP_CONCRETEFACTORY_H
