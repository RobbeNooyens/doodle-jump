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

void states::GameErrorState::update(double elapsed) {

}

void states::GameErrorState::draw(std::shared_ptr<wrappers::WindowWrapper> ptr) {

}

states::GameErrorState::GameErrorState(std::shared_ptr<EntityFactory>& factory): GameState(GameStateType::ERROR, factory) {}
