//
// Created by robnoo on 25/11/21.
//

#include "PlayerController.h"
#include "../../libraries/json.hpp"
#include "../events/Event.h"
#include "../events/KeyPressedEvent.h"

void controllers::PlayerController::handle(std::shared_ptr<Event>& event) {
    auto playerView = std::static_pointer_cast<views::PlayerView>(view);
    auto playerModel = std::static_pointer_cast<models::PlayerModel>(model);
    if (event->getType() == EventType::KEY_PRESSED) {
        std::shared_ptr<KeyPressedEvent> keyPressed = std::static_pointer_cast<KeyPressedEvent>(event);
        if(keyPressed->getAction() == KeyAction::MOVE_RIGHT) {
            playerView->lookRight();
            playerModel->moveHorizontal(Direction::RIGHT);
        } else if(keyPressed->getAction() == KeyAction::MOVE_LEFT) {
            playerView->lookLeft();
            playerModel->moveHorizontal(Direction::LEFT);
        }
    }
}

controllers::PlayerController::PlayerController(): EntityController(EntityType::PLAYER) {
    model = std::make_shared<models::PlayerModel>();
    view = std::make_shared<views::PlayerView>();
}
