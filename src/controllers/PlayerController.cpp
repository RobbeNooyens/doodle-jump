//
// Created by robnoo on 25/11/21.
//

#include <fstream>
#include "PlayerController.h"
#include "../models/PlayerModel.h"
#include "../../libraries/json.hpp"
#include "../events/Event.h"
#include "../events/KeyPressedEvent.h"
#include "../utils/ResourceLoader.h"



void controllers::PlayerController::handle(std::shared_ptr<Event>& event) {
    if (event->getType() == EventType::KEY_PRESSED) {
        std::shared_ptr<KeyPressedEvent> keyPressed = std::static_pointer_cast<KeyPressedEvent>(event);
        if(keyPressed->getAction() == KeyAction::LEFT) {
            playerView->changeX(-5);
        }
    }
}

void controllers::PlayerController::load(double size) {
    std::string entity_id = "player", texture_id = "left";
    playerModel->setSize(size);
    playerView->setTexture(ResourceLoader::getInstance().getTexture(entity_id, texture_id));
    playerView->setSize(size);

}

sf::Sprite& controllers::PlayerController::getSprite() {
    return playerView->getSprite();
}

controllers::PlayerController::PlayerController() {
    playerModel = std::make_shared<models::PlayerModel>();
    playerView = std::make_shared<views::PlayerView>();
}

void controllers::PlayerController::update(double elapsed) {
    playerModel->update(elapsed);
    playerView->moveTo(playerModel->getX(), playerModel->getY());
}

void controllers::PlayerController::moveTo(double x, double y) {
    playerModel->moveTo(x, y);
    playerView->moveTo(x, y);
}
