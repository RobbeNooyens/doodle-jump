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
