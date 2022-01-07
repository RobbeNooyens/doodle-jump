//
// Created by robbe on 20/11/2021.
//

#ifndef DOODLEJUMP_GAME_H
#define DOODLEJUMP_GAME_H

#include <memory>
#include "GameStateControl.h"

class WindowWrapper;
class WrapperFactory;
class EventWrapper;
class GameState;
class EntityFactory;

class Game {
public:
    Game();
    void run();

private:
    bool running = true;

    void checkEvents();
    void checkKeyboardInput();

    std::shared_ptr<GameStateControl> stateControl;

    std::shared_ptr<EntityFactory> entityFactory;

    std::shared_ptr<WrapperFactory> wrapperFactory;
    std::shared_ptr<WindowWrapper> window;
    std::shared_ptr<EventWrapper> event;
};


#endif //DOODLEJUMP_GAME_H
