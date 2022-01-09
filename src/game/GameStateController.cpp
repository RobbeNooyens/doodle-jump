//
// Created by robnoo on 6/01/22.
//

#include <iostream>
#include "GameStateController.h"
#include "../events/Event.h"
#include "../events/KeyPressedEvent.h"
#include "states/GameMenuState.h"
#include "states/GameOverState.h"
#include "states/GamePlayingState.h"
#include "states/GameErrorState.h"
#include "../world/World.h"
#include "../score/ScoreManager.h"
#include "../exceptions/Exception.h"

void GameStateController::handle(std::shared_ptr<events::Event> &event) {
    if(event->getType() == GameEventType::PLAYER_DIED) {
        shouldReplaceState = true;
        replaceWith = GAME_OVER;
        ScoreManager::getInstance().writeHighScore();
    } else if(event->getType() == GameEventType::KEY_PRESSED) {
        auto keyPressedEvent = std::static_pointer_cast<events::KeyPressedEvent>(event);
        if(keyPressedEvent->getKey() == Keyboard::SPACEBAR) {
            switch (state->getType()) {
                case MENU:
                    replaceState(PLAYING);
                    break;
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

void GameStateController::update(double elapsed) {
    try {
        state->update(elapsed);
        if(shouldReplaceState) {
            shouldReplaceState = false;
            replaceState(replaceWith);
        }
    } catch (exceptions::Exception& e) {
        replaceState(ERROR);
        std::cerr << e.what() << std::endl;
    }

}

void GameStateController::draw(std::shared_ptr<wrappers::WindowWrapper> &window) {
    state->draw(window);
}

void GameStateController::replaceState(GameStateType gameStateType) {
    state.reset();
    switch (gameStateType) {
        case MENU:
            state = std::make_shared<GameMenuState>(factory);
            break;
        case PLAYING:
            state = std::make_shared<GamePlayingState>(factory);
            break;
        case GAME_OVER:
            state = std::make_shared<GameOverState>(factory);
            break;
        case ERROR:
            state = std::make_shared<GameErrorState>(factory);
            break;
    }
    update(0);
}

GameStateController::GameStateController(std::shared_ptr<EntityFactory>& factory):
    state(std::make_unique<GameMenuState>(factory)),
    factory(factory) {
}
