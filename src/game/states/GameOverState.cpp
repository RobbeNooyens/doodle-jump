//
// Created by robnoo on 6/01/22.
//

#include "GameOverState.h"

void GameOverState::update(double elapsed) {

}

void GameOverState::draw(std::shared_ptr<WindowWrapper> ptr) {

}

GameOverState::GameOverState(std::shared_ptr<EntityFactory>& factory): GameState(GameStateType::GAME_OVER, factory) {}