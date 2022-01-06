//
// Created by robbe on 20/11/2021.
//

#ifndef DOODLEJUMP_GAME_H
#define DOODLEJUMP_GAME_H

#include <memory>

class WindowWrapper;

class Game {
public:
    Game();
    void run();

private:
    std::unique_ptr<WindowWrapper> window;
};


#endif //DOODLEJUMP_GAME_H
