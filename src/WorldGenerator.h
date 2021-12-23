//
// Created by robnoo on 4/12/21.
//

#ifndef DOODLEJUMP_WORLDGENERATOR_H
#define DOODLEJUMP_WORLDGENERATOR_H


#include "events/EventHandler.h"
#include "enums/PlatformType.h"
#include "factories/AbstractFactory.h"

class WorldGenerator {
public:
    WorldGenerator();
    void update();

private:
    double previousHeight;
    double nextHeight;

    const double heightDifference;

    bool addBonus = false;
    BonusType bonusType = SPRING;

    PlatformType nextPlatformType = STATIC;

    void generatePlatform();

    void calculateNextPlatformHeight();
};


#endif //DOODLEJUMP_WORLDGENERATOR_H
