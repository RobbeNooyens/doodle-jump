//
// Created by robnoo on 6/01/22.
//

#ifndef DOODLEJUMP_GAMEOVERSTATE_H
#define DOODLEJUMP_GAMEOVERSTATE_H


#include "GameState.h"

class GameOverState: public GameState {
public:
    GameOverState();

    void update(double elapsed) override;
    void draw(std::shared_ptr<WindowWrapper> ptr) override;

};


#endif //DOODLEJUMP_GAMEOVERSTATE_H
