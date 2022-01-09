//
// Created by robnoo on 25/11/21.
//

#ifndef DOODLEJUMP_PLATFORMCONTROLLER_H
#define DOODLEJUMP_PLATFORMCONTROLLER_H

#include <memory>
#include "EntityController.h"
#include "../enums/PlatformType.h"

class Event;

namespace controllers {

    class BonusController;

    class PlatformController: public EntityController {
    public:
        // Constructor
        explicit PlatformController(PlatformType type);

        // Actions
        void handle(std::shared_ptr<events::Event> &event) override;
        void goesBeneathScreen() override;

        // Getters
        PlatformType getType();
        bool isBeneathScreen();

        // Setters
        void setBonus(std::shared_ptr<BonusController>& bonusController);

    private:
        std::weak_ptr<BonusController> bonus;
        PlatformType platformType;
        int jumpCount = 0;
    };

    class StaticPlatformController: public PlatformController {
    public:
        StaticPlatformController();
    };

    class TemporaryPlatformController: public PlatformController {
    public:
        TemporaryPlatformController();
    };

    class HorizontalPlatformController: public PlatformController {
    public:
        HorizontalPlatformController();
    };

    class VerticalPlatformController: public PlatformController {
    public:
        VerticalPlatformController();
    };
}


#endif //DOODLEJUMP_PLATFORMCONTROLLER_H
