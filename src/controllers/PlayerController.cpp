//
// Created by robnoo on 25/11/21.
//

#include "PlayerController.h"
#include "../events/Event.h"
#include "../events/KeyPressedEvent.h"
#include "../events/PlayerUsesBonusEvent.h"
#include "../events/PlayerBouncesOnPlatformEvent.h"

void controllers::PlayerController::handle(std::shared_ptr<Event>& event) {
    auto playerView = std::static_pointer_cast<views::PlayerView>(view);
    auto playerModel = std::static_pointer_cast<models::PlayerModel>(model);

    // Key pressed
    if (event->getType() == GameEventType::KEY_PRESSED) {
        std::shared_ptr<KeyPressedEvent> keyPressed = std::static_pointer_cast<KeyPressedEvent>(event);
        if(keyPressed->getKey() == Keyboard::ARROW_RIGHT || keyPressed->getKey() == Keyboard::D) {
            playerModel->moveHorizontal(Direction::RIGHT);
            playerView->updateDirections(Direction::RIGHT, playerModel->getVerticalDirection());
        } else if(keyPressed->getKey() == Keyboard::ARROW_LEFT || keyPressed->getKey() == Keyboard::A) {
            playerModel->moveHorizontal(Direction::LEFT);
            playerView->updateDirections(Direction::LEFT, playerModel->getVerticalDirection());
        }
    }

    // Bonus
    if(event->getType() == GameEventType::PLAYER_USES_BONUS) {
        std::shared_ptr<PlayerUsesBonusEvent> bonusEvent = std::static_pointer_cast<PlayerUsesBonusEvent>(event);
        playerModel->useBonus(bonusEvent->getBonusType(), bonusEvent->getSurfaceHeight());
    }

    // Platform
    if(event->getType() == GameEventType::PLAYER_BOUNCES_ON_PLATFORM) {
        std::shared_ptr<PlayerBouncesOnPlatformEvent> platformEvent = std::static_pointer_cast<PlayerBouncesOnPlatformEvent>(event);
        playerModel->bounceOnPlatform(platformEvent->getSurfaceHeight());
    }
}

controllers::PlayerController::PlayerController(): EntityController() {
    model = std::make_shared<models::PlayerModel>();
    view = std::make_shared<views::PlayerView>();
}

void controllers::PlayerController::update(double elapsed) {
    EntityController::update(elapsed);
    auto pModel = std::static_pointer_cast<models::PlayerModel>(model);
    auto pView = std::static_pointer_cast<views::PlayerView>(view);
    pView->updateDirections(pModel->getHorizontalDirection(), pModel->getVerticalDirection());
}
