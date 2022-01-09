//
// Created by robnoo on 6/01/22.
//

#ifndef DOODLEJUMP_GAMESTATECONTROLLER_H
#define DOODLEJUMP_GAMESTATECONTROLLER_H


#include "states/GameState.h"
#include "../enums/GameStateType.h"
#include "../events/EventHandler.h"

class EntityFactory;

class GameStateController: public EventHandler {
public:
    explicit GameStateController(std::shared_ptr<EntityFactory>& factory);

    void handle(std::shared_ptr<events::Event> &event) override;

    void update(double elapsed);
    void draw(std::shared_ptr<wrappers::WindowWrapper>& window);

private:
    std::shared_ptr<GameState> state;
    std::shared_ptr<EntityFactory> factory;

    bool shouldReplaceState = false;
    GameStateType replaceWith = GameStateType::MENU;

    void replaceState(GameStateType gameStateType);
};


#endif //DOODLEJUMP_GAMESTATECONTROLLER_H
