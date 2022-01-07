//
// Created by robnoo on 6/01/22.
//

#include "GameStateControl.h"
#include "../events/Event.h"
#include "../events/KeyPressedEvent.h"
#include "states/GameMenuState.h"
#include "states/GameOverState.h"
#include "states/GamePlayingState.h"
#include "states/GameErrorState.h"
#include "../World.h"

void GameStateControl::handle(std::shared_ptr<Event> &event) {
    if(event->getType() == GameEventType::PLAYER_DIED) {
        replaceState(GAME_OVER);
    } else if(event->getType() == GameEventType::KEY_PRESSED) {
        auto keyPressedEvent = std::static_pointer_cast<KeyPressedEvent>(event);
        if(keyPressedEvent->getKey() == Keyboard::SPACEBAR) {
            switch (state->getType()) {
                case MENU:
                    replaceState(PLAYING);
                case PLAYING:
                    break;
                case GAME_OVER:
                case ERROR:
                    replaceState(MENU);
                    break;
            }
        }
    }
}

void GameStateControl::update(double elapsed) {
    state->update(elapsed);
}

void GameStateControl::draw(std::shared_ptr<WindowWrapper> &window) {
    state->draw(window);
}

void GameStateControl::replaceState(GameStateType gameStateType) {
    state.reset();
    switch (gameStateType) {
        case MENU:
            state = std::make_unique<GameMenuState>(factory);
            break;
        case PLAYING:
            state = std::make_unique<GamePlayingState>(factory);
            break;
        case GAME_OVER:
            state = std::make_unique<GameOverState>(factory);
            break;
        case ERROR:
            state = std::make_unique<GameErrorState>(factory);
            break;
    }

}

GameStateControl::GameStateControl(std::shared_ptr<EntityFactory>& factory):
    state(std::make_unique<GameMenuState>(factory)),
    factory(factory) {}
