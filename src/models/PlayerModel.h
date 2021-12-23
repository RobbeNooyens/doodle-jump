//
// Created by robnoo on 25/11/21.
//

#ifndef DOODLEJUMP_PLAYERMODEL_H
#define DOODLEJUMP_PLAYERMODEL_H

#include "EntityModel.h"
#include "../utils/ResourceLoader.h"
#include "../enums/Direction.h"
#include "../enums/BonusType.h"

namespace models {
    class PlayerModel: public EntityModel {
    public:
        PlayerModel();

        void update(double elapsed) override;

        void moveHorizontal(Direction direction);

        void useBonus(BonusType bonusType, double surfaceHeight);
        void bounceOnPlatform(double surfaceHeight);

    private:
        const double acceleration = 15;
        double speed = 20, boost = 1;
        const double jumpHeight = 1.2;
        Direction verticalDirection = Direction::UP;
        Direction horizontalDirection = Direction::RIGHT;

        bool moveXAxis = false;

        bool falling();
        bool jumping();

        void bounce(double from);

        double highest = 0;


    };
}



#endif //DOODLEJUMP_PLAYERMODEL_H
