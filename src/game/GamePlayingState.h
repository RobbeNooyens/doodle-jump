//
// Created by robnoo on 6/01/22.
//

#ifndef DOODLEJUMP_GAMEPLAYINGSTATE_H
#define DOODLEJUMP_GAMEPLAYINGSTATE_H


#include "GameState.h"

class World;
class AbstractFactory;

class GamePlayingState: public GameState {
public:
    GamePlayingState();

    void update(double elapsed) override;
    void redraw(std::shared_ptr<WindowWrapper> ptr) override;

private:
    std::unique_ptr<World> world;
    std::shared_ptr<AbstractFactory> factory;

};


#endif //DOODLEJUMP_GAMEPLAYINGSTATE_H
