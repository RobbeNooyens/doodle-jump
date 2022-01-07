//
// Created by robnoo on 6/01/22.
//

#include "GamePlayingState.h"

#include "../World.h"
#include "../factories/ConcreteFactory.h"

void GamePlayingState::update(double elapsed) {
    world->update(elapsed);
}

void GamePlayingState::redraw(std::shared_ptr<WindowWrapper> window) {
    world->draw(window);
}

GamePlayingState::GamePlayingState():
    GameState(GameStateType::PLAYING),
    factory(std::make_shared<ConcreteFactory>()),
    world(std::make_unique<World>(factory))
    {}
