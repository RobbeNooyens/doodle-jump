/**
 *  ╒══════════════════════════════════════╕
 *  │                                      │
 *  │             Doodle Jump              │
 *  │        Advanced Programming          │
 *  │                                      │
 *  │            Robbe Nooyens             │
 *  │    s0201010@student.uantwerpen.be    │
 *  │                                      │
 *  │        University of Antwerp         │
 *  │                                      │
 *  ╘══════════════════════════════════════╛
 */

#ifndef DOODLEJUMP_GAMEMENUSTATE_H
#define DOODLEJUMP_GAMEMENUSTATE_H


#include "GameState.h"

namespace wrappers {
    class SpriteWrapper;
    class WindowWrapper;
}

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
