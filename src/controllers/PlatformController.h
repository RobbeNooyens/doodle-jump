//
// Created by robnoo on 25/11/21.
//

#ifndef DOODLEJUMP_PLATFORMCONTROLLER_H
#define DOODLEJUMP_PLATFORMCONTROLLER_H

#include <memory>
#include "../models/PlatformModel.h"
#include "../views/PlatformView.h"
#include "EntityController.h"
#include "../enums/PlatformType.h"

namespace controllers {
    class PlatformController: public EntityController {
    public:
        // Constructor
        PlatformController();

        // Actions
        void handle(std::shared_ptr<Event> &event) override;

        // Getters
        virtual PlatformType getType() = 0;
    };

    class StaticPlatformController: public PlatformController {
    public:
        StaticPlatformController();

        PlatformType getType() override;
    };

    class TemporaryPlatformController: public PlatformController {
    public:
        TemporaryPlatformController();

        PlatformType getType() override;
    };

    class HorizontalPlatformController: public PlatformController {
    public:
        HorizontalPlatformController();

        PlatformType getType() override;
    };

    class VerticalPlatformController: public PlatformController {
    public:
        VerticalPlatformController();

        PlatformType getType() override;
    };
}


#endif //DOODLEJUMP_PLATFORMCONTROLLER_H
