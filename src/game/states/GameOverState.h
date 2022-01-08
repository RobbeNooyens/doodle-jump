//
// Created by robnoo on 6/01/22.
//

#ifndef DOODLEJUMP_GAMEOVERSTATE_H
#define DOODLEJUMP_GAMEOVERSTATE_H


#include "GameState.h"

class SpriteWrapper;

class GameOverState: public GameState {
public:
    explicit GameOverState(std::shared_ptr<EntityFactory>& factory);
    ~GameOverState();

    void update(double elapsed) override;
    void draw(std::shared_ptr<WindowWrapper> ptr) override;

private:
    std::shared_ptr<SpriteWrapper> gameover;

};


#endif //DOODLEJUMP_GAMEOVERSTATE_H
