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

class World: public EventHandler {
public:
    void clear();

    void setup();

    void handle(std::shared_ptr<Event> &event) override;

    void update(double elapsed);

    void redraw(sf::RenderWindow& window);

    std::shared_ptr<controllers::PlayerController>& getPlayer();

    std::vector<std::shared_ptr<controllers::PlatformController>> getPlatforms();
    std::vector<std::shared_ptr<controllers::BonusController>>& getBonuses();
    void addPlatform(std::shared_ptr<controllers::PlatformController>& platform);

    void addBonus(std::shared_ptr<controllers::BonusController>& bonus);

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
};


#endif //DOODLEJUMP_WORLD_H
