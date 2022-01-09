//
// Created by robnoo on 6/01/22.
//

#include "GamePlayingState.h"
#include "../../world/World.h"
#include "../../world/WorldGenerator.h"
#include "../../world/Camera.h"
#include "../../score/ScoreManager.h"

void GamePlayingState::update(double elapsed) {
    world->update(elapsed);
    worldGenerator->update();
}

void GamePlayingState::draw(std::shared_ptr<WindowWrapper> window) {
    world->draw(window);
}

GamePlayingState::GamePlayingState(std::shared_ptr<EntityFactory>& factory): GameState(GameStateType::PLAYING, factory) {
    ScoreManager::getInstance().setScore(0);
    world = std::make_shared<World>();
    worldGenerator = std::make_shared<WorldGenerator>(world, factory);
}

GamePlayingState::~GamePlayingState() {
    world.reset();
    worldGenerator->reset();
}
