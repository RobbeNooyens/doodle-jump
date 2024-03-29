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

/**
 * @brief Represents a game world with entities
 */
class World {
public:
    // Constructor - destructor
    /**
     * @brief Constructor
     */
    World();
    /**
     * @brief Destructor
     */
    ~World();

    /**
     * Updates entities in the world based on the elapsed time
     * @param elapsed elapsed nanoseconds since last frame
     */
    void update(double elapsed);
    /**
     * @brief draws all entities in the window
     * @param window window to draw entities in
     */
    void draw(std::shared_ptr<wrappers::WindowWrapper>& window);

private:
    friend class WorldGenerator;

    std::shared_ptr<Camera> camera{};

    std::shared_ptr<controllers::PlayerController> player{};
    std::shared_ptr<controllers::TextController> score{};

    std::vector<std::shared_ptr<controllers::PlatformController>> platforms{};
    std::vector<std::shared_ptr<controllers::BonusController>> bonuses{};
    std::vector<std::shared_ptr<controllers::TileController>> tiles{};

    void checkCollisions(double previousPlayerBottom);

};


#endif //DOODLEJUMP_WORLD_H
