//
// Created by robnoo on 6/01/22.
//

#include "GameMenuState.h"

#include "../../wrappers/SpriteWrapper.h"

#include "../../factories/EntityFactory.h"

void GameMenuState::update(double elapsed) {

}

void GameMenuState::draw(std::shared_ptr<WindowWrapper> ptr) {

}

GameMenuState::GameMenuState(std::shared_ptr<EntityFactory>& factory): GameState(GameStateType::MENU, factory) {
}
