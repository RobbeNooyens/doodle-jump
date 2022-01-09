//
// Created by robnoo on 6/01/22.
//

#ifndef DOODLEJUMP_GAMEMENUSTATE_H
#define DOODLEJUMP_GAMEMENUSTATE_H


#include "GameState.h"

namespace wrappers {
    class SpriteWrapper;
    class WindowWrapper;
}
class TileController;

class GameMenuState: public GameState {
public:
    explicit GameMenuState(std::shared_ptr<EntityFactory>& factory);
    ~GameMenuState();

    void update(double elapsed) override;
    void draw(std::shared_ptr<wrappers::WindowWrapper> window) override;

private:
    std::shared_ptr<wrappers::SpriteWrapper> menu;
};


#endif //DOODLEJUMP_GAMEMENUSTATE_H
