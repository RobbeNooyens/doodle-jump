//
// Created by robnoo on 6/01/22.
//

#ifndef DOODLEJUMP_GAMEMENUSTATE_H
#define DOODLEJUMP_GAMEMENUSTATE_H


#include "GameState.h"

class TileController;

class GameMenuState: public GameState {
public:
    explicit GameMenuState(std::shared_ptr<EntityFactory>& factory);

    void update(double elapsed) override;
    void draw(std::shared_ptr<WindowWrapper> window) override;

private:
    std::shared_ptr<TileController> menu;
};


#endif //DOODLEJUMP_GAMEMENUSTATE_H
