//
// Created by robnoo on 25/11/21.
//

#ifndef DOODLEJUMP_BONUSVIEW_H
#define DOODLEJUMP_BONUSVIEW_H

#include "EntityView.h"

namespace views {
    class BonusView: public EntityView {
    public:
        explicit BonusView(std::shared_ptr<EntityController> controller);
    };
}

#endif //DOODLEJUMP_BONUSVIEW_H
