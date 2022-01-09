//
// Created by robnoo on 6/01/22.
//

#include "GameErrorState.h"

void GameErrorState::update(double elapsed) {

}

void GameErrorState::draw(std::shared_ptr<wrappers::WindowWrapper> ptr) {

}

GameErrorState::GameErrorState(std::shared_ptr<EntityFactory>& factory): GameState(GameStateType::ERROR, factory) {}
