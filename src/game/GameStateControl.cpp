//
// Created by robnoo on 6/01/22.
//

#include "GameStateControl.h"
#include "../events/Event.h"

std::shared_ptr<GameState> &GameStateControl::getCurrentState() {
    return state;
}

void GameStateControl::handle(std::shared_ptr<Event> &event) {
    if(event->getType() == GameEventType::PLAYER_DIED) {

    }
}
