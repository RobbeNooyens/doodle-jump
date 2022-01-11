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

#ifndef DOODLEJUMP_GAMEPLAYINGSTATE_H
#define DOODLEJUMP_GAMEPLAYINGSTATE_H


#include "GameState.h"

class World;
class WorldGenerator;
class EntityFactory;

namespace states {
    /**
     * @brief Represents game state when playing
     */
    class GamePlayingState : public GameState {
    public:
        /**
         * @brief Parameter Constructor
         * @param factory factory used to create new entity instances
         */
        explicit GamePlayingState(std::shared_ptr<EntityFactory> &factory);
        /**
         * @brief Destructor
         */
        ~GamePlayingState() override;

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
        std::shared_ptr<World> world{};
        std::shared_ptr<WorldGenerator> worldGenerator{};
    };
}


#endif //DOODLEJUMP_GAMEPLAYINGSTATE_H
