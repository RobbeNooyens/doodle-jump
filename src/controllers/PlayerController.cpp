//
// Created by robnoo on 25/11/21.
//

#include <fstream>
#include "PlayerController.h"
#include "../../libraries/json.hpp"
#include "../events/Event.h"
#include "../events/KeyPressedEvent.h"

void controllers::PlayerController::handle(std::shared_ptr<Event>& event) {
    std::shared_ptr<views::PlayerView> playerView = std::static_pointer_cast<views::PlayerView>(view);
    if (event->getType() == EventType::KEY_PRESSED) {
        std::shared_ptr<KeyPressedEvent> keyPressed = std::static_pointer_cast<KeyPressedEvent>(event);
        if(keyPressed->getAction() == KeyAction::MOVE_RIGHT) {
            playerView->lookRight();
        } else if(keyPressed->getAction() == KeyAction::MOVE_LEFT) {
            playerView->lookLeft();
        }
    }
}

controllers::PlayerController::PlayerController() {
    model = std::make_shared<models::PlayerModel>();
    view = std::make_shared<views::PlayerView>();
}
