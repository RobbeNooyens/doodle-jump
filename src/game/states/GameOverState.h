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
    /**
     * @brief Represents game state when player dies
     */
    class GameOverState : public GameState {
    public:
        /**
         * @brief Parameter Constructor
         * @param factory factory used to create new entity instances
         */
        explicit GameOverState(std::shared_ptr<EntityFactory> &factory);
        /**
         * @brief Destructor
         */
        ~GameOverState();

        /**
         * @brief Update state based on the elapsed time
         * @param elapsed elapsed seconds since last frame
         */
        void update(double elapsed) override;
        /**
         * @brief Draws state content to the given window
         * @param window window to draw content on
         */
        void draw(std::shared_ptr<wrappers::WindowWrapper> ptr) override;

    private:
        std::shared_ptr<wrappers::SpriteWrapper> gameover;
        std::shared_ptr<controllers::TextController> score;
        std::shared_ptr<controllers::TextController> highScore;
    };
}


#endif //DOODLEJUMP_GAMEOVERSTATE_H
