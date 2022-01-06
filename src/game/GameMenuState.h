//
// Created by robnoo on 6/01/22.
//

#ifndef DOODLEJUMP_GAMEMENUSTATE_H
#define DOODLEJUMP_GAMEMENUSTATE_H


#include "GameState.h"

class GameMenuState: public GameState {
public:
    GameMenuState();

    void update(double elapsed) override;
    void redraw(std::shared_ptr<WindowWrapper> ptr) override;

};


#endif //DOODLEJUMP_GAMEMENUSTATE_H
