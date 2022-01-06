//
// Created by robbe on 20/11/2021.
//

#ifndef DOODLEJUMP_WORLD_H
#define DOODLEJUMP_WORLD_H


#include <vector>
#include <memory>
#include "enums/GameStateType.h"
#include "factories/AbstractFactory.h"

class WindowWrapper;
class WorldGenerator;
class TextWrapper;

namespace controllers {
    class PlayerController;
    class PlatformController;
    class BonusController;
    class TileController;
}

class World: public::std::enable_shared_from_this<World> {
public:
    explicit World(std::shared_ptr<AbstractFactory>& factory);

    void clear();
    void update(double elapsed);
    void draw(std::shared_ptr<WindowWrapper>& window);

    void addPlatform(std::shared_ptr<controllers::PlatformController>& platform);
    void addBonus(std::shared_ptr<controllers::BonusController>& bonus);
    void addTile(std::shared_ptr<controllers::TileController>& tile);

    void checkCollisions(double previousPlayerBottom);

private:
    const std::unique_ptr<WorldGenerator> worldGenerator;
    std::unique_ptr<controllers::PlayerController> player;

    std::vector<std::shared_ptr<controllers::PlatformController>> platforms;
    std::vector<std::shared_ptr<controllers::BonusController>> bonuses;
    std::vector<std::shared_ptr<controllers::TileController>> tiles;

    std::shared_ptr<TextWrapper> score;

};


#endif //DOODLEJUMP_WORLD_H
