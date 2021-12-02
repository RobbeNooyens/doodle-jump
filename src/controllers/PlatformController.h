//
// Created by robnoo on 25/11/21.
//

#ifndef DOODLEJUMP_PLATFORMCONTROLLER_H
#define DOODLEJUMP_PLATFORMCONTROLLER_H

#include <memory>
#include "../models/PlatformModel.h"
#include "../views/PlatformView.h"
#include "EntityController.h"

namespace controllers {
    class PlatformController: public EntityController {
    public:
        // Constructor
        PlatformController();

        // Actions
        void handle(std::shared_ptr<Event> &event) override;
        void update(double elapsed) override;
        void moveTo(double x, double y) override;
        void load(double width) override = 0;

        // Getters
        sf::Sprite &getSprite() override;

    protected:
        std::shared_ptr<models::PlatformModel> platformModel;
        std::shared_ptr<views::PlatformView> platformView;
        std::string entityType = "platform";

    };

    class StaticPlatformController: public PlatformController {
    public:
        // Loaders
        void load(double width) override;
    };
}


#endif //DOODLEJUMP_PLATFORMCONTROLLER_H
