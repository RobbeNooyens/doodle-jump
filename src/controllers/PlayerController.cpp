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

        }
    }
}

void controllers::PlayerController::load(std::string &entityJsonFile) {
    std::string entity_id = "player", texture_id = "left";
    (*playerView).setTexture(ResourceLoader::getInstance().getTexture(entity_id, texture_id));

}

sf::Sprite& controllers::PlayerController::getSprite() {
    return playerView->getSprite();
}

controllers::PlayerController::PlayerController() {
    playerModel = std::make_shared<models::PlayerModel>(models::PlayerModel());
    playerView = std::make_shared<views::PlayerView>(views::PlayerView());
}
