//
// Created by robnoo on 6/01/22.
//

#ifndef DOODLEJUMP_GAMESTATECONTROL_H
#define DOODLEJUMP_GAMESTATECONTROL_H


#include "../enums/GameStateType.h"
#include "GameState.h"
#include "../events/EventHandler.h"

class GameStateControl: public EventHandler {
public:
    std::shared_ptr<GameState>& getCurrentState();

    void handle(std::shared_ptr<Event> &event) override;

private:
    GameStateType currentState;
    std::shared_ptr<GameState> state;

};


#endif //DOODLEJUMP_GAMESTATECONTROL_H
