//
// Created by robnoo on 6/01/22.
//

#ifndef DOODLEJUMP_GAMEERRORSTATE_H
#define DOODLEJUMP_GAMEERRORSTATE_H


#include "GameState.h"

class GameErrorState: public GameState {
public:
    GameErrorState();

    void update(double elapsed) override;
    void draw(std::shared_ptr<WindowWrapper> ptr) override;

};


#endif //DOODLEJUMP_GAMEERRORSTATE_H
