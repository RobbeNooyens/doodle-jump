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
    void reset();

private:
    double previousHeight = 0;
    double nextHeight = 0;

    const double heightDifference = 0;

    bool addBonus = false;
    BonusType bonusType = SPRING;

    PlatformType nextPlatformType = STATIC;

    void generatePlatform();

    void calculateNextPlatformHeight();
};


#endif //DOODLEJUMP_WORLDGENERATOR_H
