//
// Created by robnoo on 25/11/21.
//

#ifndef DOODLEJUMP_PLAYERCONTROLLER_H
#define DOODLEJUMP_PLAYERCONTROLLER_H

#include <memory>
#include <SFML/Graphics/Sprite.hpp>
#include "../models/PlayerModel.h"
#include "../views/PlayerView.h"
#include "EntityController.h"

class Event;

namespace controllers {
    class PlayerController: public EntityController {
    public:
        PlayerController();

        void handle(std::shared_ptr<Event>& event) override;

        void load(std::string &entityJsonFile) override;

        sf::Sprite& getSprite() override;


    private:
        std::shared_ptr<models::PlayerModel> playerModel;
        std::shared_ptr<views::PlayerView> playerView;

    };
}


#endif //DOODLEJUMP_PLAYERCONTROLLER_H
