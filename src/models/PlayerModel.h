//
// Created by robnoo on 25/11/21.
//

#ifndef DOODLEJUMP_PLAYERMODEL_H
#define DOODLEJUMP_PLAYERMODEL_H

#include "EntityModel.h"
#include "../utils/ResourceLoader.h"
#include "../enums/Direction.h"
#include "../enums/BonusType.h"
#include "../Settings.h"

namespace models {
    class PlayerModel: public EntityModel {
    public:
        PlayerModel();

        void update(double elapsed) override;

        void moveHorizontal(Direction direction);
        void useBonus(BonusType bonusType, double surfaceHeight);
        void bounceOnPlatform(double surfaceHeight);

    private:
        double speed = 15, boost = 1;
        Direction verticalDirection = Direction::UP;
        Direction horizontalDirection = Direction::RIGHT;

        bool moveXAxis = false;

        void bounce(double from);
        void checkMaxHeight();
    };
}



#endif //DOODLEJUMP_PLAYERMODEL_H
