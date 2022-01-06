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
    GameStateControl();

    void handle(std::shared_ptr<Event> &event) override;

    void update(double elapsed);
    void redraw(std::shared_ptr<WindowWrapper>& window);

private:
    std::unique_ptr<GameState> state;

    void replaceState(GameStateType gameStateType);
};


#endif //DOODLEJUMP_GAMESTATECONTROL_H
