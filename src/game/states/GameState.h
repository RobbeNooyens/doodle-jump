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

#ifndef DOODLEJUMP_GAMESTATE_H
#define DOODLEJUMP_GAMESTATE_H

#include <memory>
#include "../../enums/GameStateType.h"

namespace wrappers {
    class WindowWrapper;
}

class EntityFactory;

namespace states {
    class GameState {
    public:
        // Constructor
        /**
         * @brief Parameter constructor
         * @param type type of gamestate
         * @param factory factory used to create new entity instances
         */
        explicit GameState(GameStateType type, std::shared_ptr<EntityFactory> &factory) : gameStateType(type),
                                                                                          factory(factory) {};
        /**
         * @brief Virtual destructor
         */
        virtual ~GameState() { factory.reset(); }

        // Getters
        /**
         * @return game state type
         */
        GameStateType getType() { return gameStateType; }

        // Actions
        /**
         * @brief Update state based on the elapsed time
         * @param elapsed elapsed seconds since last frame
         */
        virtual void update(double elapsed) = 0;
        /**
         * @brief Draws state content to the given window
         * @param window window to draw content on
         */
        virtual void draw(std::shared_ptr<wrappers::WindowWrapper> window) = 0;

    protected:
        /**
         * @brief Factory used to create new entity instances
         */
        std::shared_ptr<EntityFactory> factory{};

    private:
        GameStateType gameStateType = GameStateType::MENU;
    };
}

#endif //DOODLEJUMP_GAMESTATE_H
