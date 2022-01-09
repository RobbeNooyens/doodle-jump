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

#ifndef DOODLEJUMP_GAMESTATECONTROLLER_H
#define DOODLEJUMP_GAMESTATECONTROLLER_H

#include "../enums/GameStateType.h"
#include "../events/EventHandler.h"

class EntityFactory;

namespace wrappers {
    class WindowWrapper;
}

namespace states {
    class GameState;
}

/**
 * @brief Controls the game states
 */
class GameStateController: public EventHandler {
public:
    /**
     * @brief Parameter Constructor
     * @param factory factory used to create new entity instances
     */
    explicit GameStateController(std::shared_ptr<EntityFactory>& factory);

    /**
     * @brief Handles incoming game events
     * @param event event that got invoked
     */
    void handle(std::shared_ptr<events::Event> &event) override;

    /**
     * @brief Update state based on the elapsed time
     * @param elapsed elapsed seconds since last frame
     */
    void update(double elapsed);
    /**
     * @brief Draws state content to the given window
     * @param window window to draw content on
     */
    void draw(std::shared_ptr<wrappers::WindowWrapper>& window);

private:
    std::shared_ptr<states::GameState> state;
    std::shared_ptr<EntityFactory> factory;

    bool shouldReplaceState = false;
    GameStateType replaceWith = GameStateType::MENU;

    void replaceState(GameStateType gameStateType);
};


#endif //DOODLEJUMP_GAMESTATECONTROLLER_H
