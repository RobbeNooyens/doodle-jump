/**
 *  ╒══════════════════════════════════════╕
 *  │                                      │
 *  │             Doodle Jump              │
 *  │        Advanced Programming          │
 *  │                                      │
 *  │            Robbe Nooyens             │
 *  │    s0201010@student.uantwerpen.be    │
 *  │                                      │
 *  │        University of Antwerp         │
 *  │                                      │
 *  ╘══════════════════════════════════════╛
 */

#ifndef DOODLEJUMP_WORLDGENERATOR_H
#define DOODLEJUMP_WORLDGENERATOR_H


#include <memory>
#include "../enums/PlatformType.h"
#include "../enums/BonusType.h"

class EntityFactory;
class World;

/**
 * @brief Creates entities and puts them in the world
 */
class WorldGenerator {
public:
    // Constructor - destructor
    /**
     * @brief Parameter constructor
     * @param world world to put entities in
     * @param factory factory used to create entities
     */
    WorldGenerator(std::shared_ptr<World> world, std::shared_ptr<EntityFactory>& factory);
    /**
     * @brief destructor
     */
    ~WorldGenerator();

    /**
     * @brief Update generating processes and create platforms/bonuses if necessary
     */
    void update();

private:
    double previousHeight = 0;
    double nextHeight = 0;
    const double heightDifference = 0;

    bool addBonus = false;
    BonusType bonusType = SPRING;

    PlatformType nextPlatformType = STATIC;

    std::shared_ptr<EntityFactory> factory{};
    std::weak_ptr<World> world{};

    void generatePlatform();
    void calculateNextPlatformHeight();
    void setup();
};


#endif //DOODLEJUMP_WORLDGENERATOR_H
