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

#ifndef DOODLEJUMP_GAMEERRORSTATE_H
#define DOODLEJUMP_GAMEERRORSTATE_H


#include "GameState.h"

namespace states {
    class GameErrorState : public GameState {
    public:
        explicit GameErrorState(std::shared_ptr<EntityFactory> &factory);

        void update(double elapsed) override;

        void draw(std::shared_ptr<wrappers::WindowWrapper> ptr) override;

    };
}


#endif //DOODLEJUMP_GAMEERRORSTATE_H
