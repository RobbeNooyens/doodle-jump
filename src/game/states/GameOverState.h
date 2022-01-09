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

#ifndef DOODLEJUMP_GAMEOVERSTATE_H
#define DOODLEJUMP_GAMEOVERSTATE_H


#include "GameState.h"

namespace wrappers {
    class SpriteWrapper;
}

namespace controllers {
    class TextController;
}

namespace states {
    class GameOverState : public GameState {
    public:
        explicit GameOverState(std::shared_ptr<EntityFactory> &factory);

        ~GameOverState();

        void update(double elapsed) override;

        void draw(std::shared_ptr<wrappers::WindowWrapper> ptr) override;

    private:
        std::shared_ptr<wrappers::SpriteWrapper> gameover;
        std::shared_ptr<controllers::TextController> score;
        std::shared_ptr<controllers::TextController> highScore;
    };
}


#endif //DOODLEJUMP_GAMEOVERSTATE_H
