//
// Created by robnoo on 6/01/22.
//

#include "GamePlayingState.h"

#include "../../World.h"

void GamePlayingState::update(double elapsed) {
    world->update(elapsed);
}

void GamePlayingState::draw(std::shared_ptr<WindowWrapper> window) {
    world->draw(window);
}

GamePlayingState::GamePlayingState(std::shared_ptr<EntityFactory>& factory):
    GameState(GameStateType::PLAYING, factory),
    world(std::make_shared<World>(factory))
    {}
