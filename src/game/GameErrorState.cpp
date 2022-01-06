//
// Created by robnoo on 6/01/22.
//

#include "GameErrorState.h"

void GameErrorState::update(double elapsed) {

}

void GameErrorState::redraw(std::shared_ptr<WindowWrapper> ptr) {

}

GameErrorState::GameErrorState(): GameState(GameStateType::ERROR) {}
