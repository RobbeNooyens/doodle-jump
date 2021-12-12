//
// Created by robnoo on 25/11/21.
//

#ifndef DOODLEJUMP_BONUSCONTROLLER_H
#define DOODLEJUMP_BONUSCONTROLLER_H

#include "EntityController.h"
#include "PlatformController.h"
#include "../enums/BonusType.h"

namespace controllers {
    class BonusController: public EntityController {
    public:
        BonusController();

        void handle(std::shared_ptr<Event> &event) override;

        virtual void use() = 0;

        void update(double elapsed) override;

        void setPlatform(std::shared_ptr<PlatformController>& platformController);

        BonusType getType();

    private:
        double offset = 0;
        std::shared_ptr<PlatformController> platform;

    protected:
        BonusType bonusType = BonusType::SPRING;
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
