//
// Created by robnoo on 6/01/22.
//

#include "GameStateControl.h"
#include "../events/Event.h"
#include "GameMenuState.h"
#include "GameOverState.h"
#include "../events/KeyPressedEvent.h"
#include "GamePlayingState.h"
#include "GameErrorState.h"

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
    state->redraw(window);
}

void GameStateControl::replaceState(GameStateType gameStateType) {
    state.reset();
    switch (gameStateType) {
        case MENU:
            state = std::make_unique<GameMenuState>();
            break;
        case PLAYING:
            state = std::make_unique<GamePlayingState>();
            break;
        case GAME_OVER:
            state = std::make_unique<GameOverState>();
            break;
        case ERROR:
            state = std::make_unique<GameErrorState>();
            break;
    }

}

GameStateControl::GameStateControl(): state(std::make_unique<GameMenuState>()) {}
