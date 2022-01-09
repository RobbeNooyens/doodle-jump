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

class GameStateController: public EventHandler {
public:
    explicit GameStateController(std::shared_ptr<EntityFactory>& factory);

    void handle(std::shared_ptr<events::Event> &event) override;

    void update(double elapsed);
    void draw(std::shared_ptr<wrappers::WindowWrapper>& window);

private:
    std::shared_ptr<states::GameState> state;
    std::shared_ptr<EntityFactory> factory;

    bool shouldReplaceState = false;
    GameStateType replaceWith = GameStateType::MENU;

    void replaceState(GameStateType gameStateType);
};


#endif //DOODLEJUMP_GAMESTATECONTROLLER_H
