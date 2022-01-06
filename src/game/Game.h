//
// Created by robbe on 20/11/2021.
//

#ifndef DOODLEJUMP_GAME_H
#define DOODLEJUMP_GAME_H

#include <memory>

class WindowWrapper;
class WrapperFactory;
class EventWrapper;
class GameState;

class Game {
public:
    Game();
    void run();

private:
    void checkEvents();
    void checkKeyboardInput();

    std::unique_ptr<GameState> state;

    std::shared_ptr<WrapperFactory> wrapperFactory;
    std::shared_ptr<WindowWrapper> window;
    std::shared_ptr<EventWrapper> event;
};


#endif //DOODLEJUMP_GAME_H
