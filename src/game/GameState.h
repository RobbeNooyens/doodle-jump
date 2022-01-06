//
// Created by robnoo on 6/01/22.
//

#ifndef DOODLEJUMP_GAMESTATE_H
#define DOODLEJUMP_GAMESTATE_H

#include <memory>
#include "../enums/GameStateType.h"

class WindowWrapper;

class GameState {
public:
    static GameStateType currentState;
    virtual void update(double elapsed) = 0;
    virtual void redraw(std::shared_ptr<WindowWrapper>) = 0;
};

GameStateType GameState::currentState = MENU;

#endif //DOODLEJUMP_GAMESTATE_H
