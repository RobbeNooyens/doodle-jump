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

        virtual void use() = 0;
    };

    class SpringController: public BonusController {
    public:
        SpringController();

        void use() override;
    };

    class JetpackController: public BonusController {
    public:
        JetpackController();

        void use() override;
    };
}


#endif //DOODLEJUMP_BONUSCONTROLLER_H
