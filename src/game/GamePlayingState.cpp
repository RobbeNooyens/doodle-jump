//
// Created by robnoo on 6/01/22.
//

#include "GamePlayingState.h"
#include "../World.h"

void GamePlayingState::update(double elapsed) {
    world->update(elapsed);
}

void GamePlayingState::redraw(std::shared_ptr<WindowWrapper> window) {
    world->draw(window);
}

GamePlayingState::GamePlayingState(): GameState(GameStateType::PLAYING), world(std::make_unique<World>()) {}
