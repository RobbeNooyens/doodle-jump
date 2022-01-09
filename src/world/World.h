//
// Created by robbe on 20/11/2021.
//

#ifndef DOODLEJUMP_WORLD_H
#define DOODLEJUMP_WORLD_H

#include "../factories/EntityFactory.h"

#include <vector>
#include <memory>

class WorldGenerator;
class Camera;

namespace wrappers {
    class WindowWrapper;
    class TextWrapper;
}

namespace controllers {
    class PlayerController;
    class PlatformController;
    class BonusController;
    class TileController;
    class TextController;
}

class World {
public:
    // Constructor - destructor
    World();
    ~World();

    void update(double elapsed);
    void draw(std::shared_ptr<wrappers::WindowWrapper>& window);

private:
    friend class WorldGenerator;

    std::shared_ptr<Camera> camera;

    std::shared_ptr<controllers::PlayerController> player;
    std::shared_ptr<controllers::TextController> score;

    std::vector<std::shared_ptr<controllers::PlatformController>> platforms;
    std::vector<std::shared_ptr<controllers::BonusController>> bonuses;
    std::vector<std::shared_ptr<controllers::TileController>> tiles;

    void checkCollisions(double previousPlayerBottom);

};


#endif //DOODLEJUMP_WORLD_H
