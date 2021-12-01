//
// Created by robnoo on 25/11/21.
//

#include <fstream>
#include "PlayerController.h"
#include "../models/Player.h"
#include "../../libraries/json.hpp"
#include "../events/Event.h"
#include "../events/KeyPressedEvent.h"

using json = nlohmann::json;

void controllers::PlayerController::handle(std::shared_ptr<Event>& event) {
    if (event->getType() == EventType::KEY_PRESSED) {
        std::shared_ptr<KeyPressedEvent> keyPressed = std::static_pointer_cast<KeyPressedEvent>(event);
        if(keyPressed->getAction() == KeyAction::LEFT) {

        }
    }
}

void controllers::PlayerController::load(std::string &entityJsonFile) {
    std::ifstream input("../resources/entities/" + entityJsonFile);

    std::string t = "ninja_doodler.png";
    json j;
    input >> j;


    for(const auto& texture: j["textures"]) {
        t = texture["source"];
    }

    (*playerView).setTexture(t);
}

sf::Sprite& controllers::PlayerController::getSprite() {
    return playerView->getSprite();
}

controllers::PlayerController::PlayerController() {
    playerModel = std::make_shared<models::Player>(models::Player());
    playerView = std::make_shared<views::Player>(views::Player());
}
