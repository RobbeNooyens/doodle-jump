/**
 *  ╒══════════════════════════════════════╕
 *  │                                      │
 *  │             Doodle Jump              │
 *  │        Advanced Programming          │
 *  │                                      │
 *  │            Robbe Nooyens             │
 *  │    s0201010@student.uantwerpen.be    │
 *  │                                      │
 *  │        University of Antwerp         │
 *  │                                      │
 *  ╘══════════════════════════════════════╛
 */

#include "GameErrorState.h"

void GameErrorState::update(double elapsed) {

}

void GameErrorState::draw(std::shared_ptr<wrappers::WindowWrapper> ptr) {

}

GameErrorState::GameErrorState(std::shared_ptr<EntityFactory>& factory): GameState(GameStateType::ERROR, factory) {}
