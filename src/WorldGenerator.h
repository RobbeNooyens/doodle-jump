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

    const double minHeight = 60;
    const double maxHeight = 120;
    const double heightDifference;

    PlatformType nextPlatformType = STATIC;

    void generatePlatform(PlatformType type);
    void generateBonusPlatform(PlatformType type, BonusType);

    void calculateNextPlatformHeight();
};


#endif //DOODLEJUMP_WORLDGENERATOR_H
