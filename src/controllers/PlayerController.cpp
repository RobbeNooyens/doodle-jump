//
// Created by robnoo on 25/11/21.
//

#include <fstream>
#include "PlayerController.h"
#include "../../libraries/json.hpp"
#include "../events/Event.h"
#include "../events/KeyPressedEvent.h"

void controllers::PlayerController::handle(std::shared_ptr<Event>& event) {
    if (event->getType() == EventType::KEY_PRESSED) {
        std::shared_ptr<KeyPressedEvent> keyPressed = std::static_pointer_cast<KeyPressedEvent>(event);
        if(keyPressed->getAction() == KeyAction::LEFT) {
            view->changeX(-5);
        }
    }
}

controllers::PlayerController::PlayerController() {
    model = std::make_shared<models::PlayerModel>();
    view = std::make_shared<views::PlayerView>();
}
