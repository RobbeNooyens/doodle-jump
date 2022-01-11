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

namespace states {
    /**
     * @brief Represents game menu
     */
    class GameMenuState : public GameState {
    public:
        /**
         * @brief Parameter Constructor
         * @param factory factory used to create new entity instances
         */
        explicit GameMenuState(std::shared_ptr<EntityFactory> &factory);
        /**
         * @brief Destructor
         */
        ~GameMenuState() override;

        /**
         * @brief Update state based on the elapsed time
         * @param elapsed elapsed seconds since last frame
         */
        void update(double elapsed) override;
        /**
         * @brief Draws state content to the given window
         * @param window window to draw content on
         */
        void draw(std::shared_ptr<wrappers::WindowWrapper> window) override;

    private:
        std::shared_ptr<wrappers::SpriteWrapper> menu{};
    };
}


#endif //DOODLEJUMP_GAMEMENUSTATE_H
