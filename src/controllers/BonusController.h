//
// Created by robnoo on 25/11/21.
//

#ifndef DOODLEJUMP_BONUSCONTROLLER_H
#define DOODLEJUMP_BONUSCONTROLLER_H

#include "EntityController.h"
#include "../enums/BonusType.h"

namespace controllers {
    class PlatformController;
}

namespace controllers {

    class BonusController: public EntityController {
    public:
        explicit BonusController(BonusType type);

        void handle(std::shared_ptr<events::Event> &event) override;

        void update(double elapsed) override;

        void setPlatform(std::shared_ptr<controllers::PlatformController>& platformController);

        BonusType getType();

    protected:
        virtual void use() = 0;

    private:
        double offset = 0;
        std::shared_ptr<PlatformController> platform;
        BonusType bonusType = BonusType::SPRING;
    };

    class SpringController: public BonusController {
    public:
        SpringController();

    protected:
        void use() override;
    };

    class JetpackController: public BonusController {
    public:
        JetpackController();

    protected:
        void use() override;
    };
}


#endif //DOODLEJUMP_BONUSCONTROLLER_H
