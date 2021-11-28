//
// Created by robnoo on 25/11/21.
//

#include <fstream>
#include "PlayerController.h"
#include "../models/Player.h"
#include "../../libraries/json.hpp"

using json = nlohmann::json;

void controllers::PlayerController::handle(Event &event) {

}

void controllers::PlayerController::load(std::string &entityJsonFile) {
    std::ifstream input(entityJsonFile);

    json j;
    input >> j;

    std::string t;

    for(const auto& texture: j["textures"]) {
        t = texture;
    }

    (*playerView).setTexture(t);
}

sf::Sprite controllers::PlayerController::getSprite() {
    return playerView->getSprite();
}

controllers::PlayerController::PlayerController() {
    playerModel = std::make_shared<models::Player>(models::Player());
    playerView = std::make_shared<views::Player>(views::Player());
}
