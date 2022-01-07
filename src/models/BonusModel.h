//
// Created by robnoo on 25/11/21.
//

#ifndef DOODLEJUMP_BONUSMODEL_H
#define DOODLEJUMP_BONUSMODEL_H

#include "EntityModel.h"
#include "PlatformModel.h"

namespace models {
    class BonusModel: public EntityModel {
    public:
        void update(double elapsed) override;

    protected:
        explicit BonusModel(std::shared_ptr<EntityController>& controller);
    };

    class SpringModel: public BonusModel {
    public:
        explicit SpringModel(std::shared_ptr<EntityController> controller);
    };

    class JetpackModel: public BonusModel {
    public:
        explicit JetpackModel(std::shared_ptr<EntityController> controller);
    };
}

#endif //DOODLEJUMP_BONUSMODEL_H
