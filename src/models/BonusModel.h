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
        BonusModel();
    };

    class SpringModel: public BonusModel {
    public:
        SpringModel();
    };

    class JetpackModel: public BonusModel {
    public:
        JetpackModel();
    };
}

#endif //DOODLEJUMP_BONUSMODEL_H
