//
// Created by robnoo on 4/12/21.
//

#ifndef DOODLEJUMP_WORLDGENERATOR_H
#define DOODLEJUMP_WORLDGENERATOR_H


#include <memory>
#include "../enums/PlatformType.h"
#include "../enums/BonusType.h"

class EntityFactory;
class World;

class WorldGenerator {
public:
    // Constructor - destructor
    WorldGenerator(std::shared_ptr<World> world, std::shared_ptr<EntityFactory>& factory);
    ~WorldGenerator();

    void update();
    void reset();

private:
    double previousHeight = 0;
    double nextHeight = 0;
    const double heightDifference = 0;

    bool addBonus = false;
    BonusType bonusType = SPRING;

    PlatformType nextPlatformType = STATIC;

    std::shared_ptr<EntityFactory> factory;
    std::weak_ptr<World> world;

    void generatePlatform();
    void calculateNextPlatformHeight();
    void setup();
};


#endif //DOODLEJUMP_WORLDGENERATOR_H
