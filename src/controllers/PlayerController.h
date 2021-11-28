//
// Created by robnoo on 25/11/21.
//

#ifndef DOODLEJUMP_PLAYERCONTROLLER_H
#define DOODLEJUMP_PLAYERCONTROLLER_H

#include <memory>
#include <SFML/Graphics/Sprite.hpp>
#include "../models/Player.h"
#include "../views/Player.h"
#include "EntityController.h"

class Event;

namespace controllers {
    class PlayerController: public EntityController {
    public:
        PlayerController();

        void handle(Event& event) override;

        void load(std::string &entityJsonFile) override;

        sf::Sprite getSprite() override;


    private:
        std::shared_ptr<models::Player> playerModel;
        std::shared_ptr<views::Player> playerView;

    };
}


#endif //DOODLEJUMP_PLAYERCONTROLLER_H
