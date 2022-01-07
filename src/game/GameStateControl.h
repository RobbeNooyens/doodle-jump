//
// Created by robnoo on 6/01/22.
//

#ifndef DOODLEJUMP_GAMESTATECONTROL_H
#define DOODLEJUMP_GAMESTATECONTROL_H


#include "states/GameState.h"
#include "../enums/GameStateType.h"
#include "../events/EventHandler.h"

class EntityFactory;

class GameStateControl: public EventHandler {
public:
    explicit GameStateControl(std::shared_ptr<EntityFactory>& factory);

    void handle(std::shared_ptr<Event> &event) override;

    void update(double elapsed);
    void draw(std::shared_ptr<WindowWrapper>& window);

private:
    std::unique_ptr<GameState> state;
    std::shared_ptr<EntityFactory> factory;

    void replaceState(GameStateType gameStateType);
};


#endif //DOODLEJUMP_GAMESTATECONTROL_H
