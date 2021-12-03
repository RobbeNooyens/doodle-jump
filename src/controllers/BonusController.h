//
// Created by robnoo on 25/11/21.
//

#ifndef DOODLEJUMP_BONUSCONTROLLER_H
#define DOODLEJUMP_BONUSCONTROLLER_H

#include "EntityController.h"

namespace controllers {
    class BonusController: public EntityController {
    public:
        BonusController();

        void handle(std::shared_ptr<Event> &event) override;
    };

    class SpringController: public BonusController {
    public:
        SpringController();
    };

    class JetpackController: public BonusController {
    public:
        JetpackController();
    };
}


#endif //DOODLEJUMP_BONUSCONTROLLER_H
