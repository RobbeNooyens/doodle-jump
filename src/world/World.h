//
// Created by robbe on 20/11/2021.
//

#ifndef DOODLEJUMP_WORLD_H
#define DOODLEJUMP_WORLD_H

#include "../factories/EntityFactory.h"

#include <vector>
#include <memory>

class WindowWrapper;
class WorldGenerator;
class TextWrapper;

namespace controllers {
    class PlayerController;
    class PlatformController;
    class BonusController;
    class TileController;
}

class World {
public:
    explicit World(std::shared_ptr<EntityFactory>& factory);

    void clear();
    void update(double elapsed);
    void draw(std::shared_ptr<WindowWrapper>& window);

private:
    friend class WorldGenerator;

    std::shared_ptr<controllers::PlayerController> player;

    std::vector<std::shared_ptr<controllers::PlatformController>> platforms;
    std::vector<std::shared_ptr<controllers::BonusController>> bonuses;
    std::vector<std::shared_ptr<controllers::TileController>> tiles;
    std::shared_ptr<TextWrapper> score;

    void checkCollisions(double previousPlayerBottom);

};


#endif //DOODLEJUMP_WORLD_H
