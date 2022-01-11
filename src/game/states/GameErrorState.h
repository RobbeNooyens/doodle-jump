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
    /**
     * @brief Represents game state when an exception has been thrown
     */
    class GameErrorState : public GameState {
    public:
        /**
         * @brief Parameter Constructor
         * @param factory factory used to create new entity instances
         */
        explicit GameErrorState(std::shared_ptr<EntityFactory> &factory);

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

    };
}


#endif //DOODLEJUMP_GAMEERRORSTATE_H
