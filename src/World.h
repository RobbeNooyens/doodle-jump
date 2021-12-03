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

class World: public EventHandler {
public:
    static World& getInstance();

    void clear();

    void setup();

    void handle(std::shared_ptr<Event> &event) override;

    void update(double elapsed);

    void redraw(sf::RenderWindow& window);

    std::shared_ptr<controllers::PlayerController>& getPlayer();
    std::vector<std::shared_ptr<controllers::PlatformController>> getPlatforms();
    std::vector<std::shared_ptr<controllers::BonusController>>& getBonuses();

    World(World const&) = delete;
    void operator=(World const&) = delete;


private:
    World();

    std::shared_ptr<controllers::PlayerController> player;
    std::vector<std::shared_ptr<controllers::PlatformController>> platforms;
    std::vector<std::shared_ptr<controllers::BonusController>> bonuses;
};


#endif //DOODLEJUMP_WORLD_H
