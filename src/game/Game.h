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
#include "GameStateController.h"

namespace wrappers {
    class WindowWrapper;

    class WrapperFactory;

    class EventWrapper;
}

class GameState;
class EntityFactory;

class Game {
public:
    Game();
    void run();

private:
    bool running = true;

    std::shared_ptr<GameStateController> stateControl;

    std::shared_ptr<EntityFactory> entityFactory;

    std::shared_ptr<wrappers::WrapperFactory> wrapperFactory;
    std::shared_ptr<wrappers::WindowWrapper> window;
    std::shared_ptr<wrappers::EventWrapper> event;
};


#endif //DOODLEJUMP_GAME_H
