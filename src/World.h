//
// Created by robbe on 20/11/2021.
//

#ifndef DOODLEJUMP_WORLD_H
#define DOODLEJUMP_WORLD_H


#include <vector>
#include "controllers/EntityController.h"
#include "controllers/PlayerController.h"
#include "controllers/PlatformController.h"
#include "controllers/BonusController.h"
#include "controllers/TileController.h"
#include "WorldGenerator.h"
#include "enums/GameStateType.h"

class World {
public:
    void clear();

    void setup();

    void update(double elapsed);

    void redraw(sf::RenderWindow& window);

    void addPlatform(std::shared_ptr<controllers::PlatformController>& platform);

    void addBonus(std::shared_ptr<controllers::BonusController>& bonus);

    void checkCollisions(double previousPlayerBottom);

    void spacebarPressed();

    // Singleton
    World(World const&) = delete;
    void operator=(World const&) = delete;
    static World& getInstance();


private:
    World();

    const std::unique_ptr<WorldGenerator> worldGenerator;

    std::shared_ptr<controllers::PlayerController> player;
    std::vector<std::shared_ptr<controllers::PlatformController>> platforms;
    std::vector<std::shared_ptr<controllers::BonusController>> bonuses;
    std::vector<std::shared_ptr<controllers::TileController>> tiles;

    GameStateType gameState = MENU;
};


#endif //DOODLEJUMP_WORLD_H
