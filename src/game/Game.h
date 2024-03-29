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

#ifndef DOODLEJUMP_GAME_H
#define DOODLEJUMP_GAME_H

#include <memory>

namespace wrappers {
    class WindowWrapper;

    class WrapperFactory;

    class EventWrapper;
}

class EntityFactory;
class GameStateController;

/**
 * @brief Represents a game instance and handles the game loop
 */
class Game {
public:
    /**
     * @brief Default constructor
     */
    Game();

    /**
     * @brief runs gameloop
     */
    void run();

private:
    bool running = true;

    std::shared_ptr<GameStateController> stateControl{};

    std::shared_ptr<EntityFactory> entityFactory{};

    std::shared_ptr<wrappers::WrapperFactory> wrapperFactory{};
    std::shared_ptr<wrappers::WindowWrapper> window{};
    std::shared_ptr<wrappers::EventWrapper> event{};
};


#endif //DOODLEJUMP_GAME_H
