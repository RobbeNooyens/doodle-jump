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
        // Constructor
        PlayerController();

        double getX() {return model->getX();}
        double getY() {return model->getY();}

        // Actions
        void handle(std::shared_ptr<Event>& event) override;
//        void update(double elapsed) override;
    };
}


#endif //DOODLEJUMP_PLAYERCONTROLLER_H
