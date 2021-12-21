//
// Created by robnoo on 25/11/21.
//

#ifndef DOODLEJUMP_PLAYERMODEL_H
#define DOODLEJUMP_PLAYERMODEL_H

#include "EntityModel.h"
#include "../utils/ResourceLoader.h"
#include "../enums/Direction.h"

namespace models {
    class PlayerModel: public EntityModel {
    public:
        PlayerModel();

        void update(double elapsed) override;

    private:
        const double acceleration = 15;
        double speed = 20;
        const double jumpHeight = 1.2;
        Direction direction = Direction::UP;

        bool falling();
        bool jumping();

        double boost = 1, rocketPower = 0;
        double highest = 0;
        double y0 = 0, a = 0.5;


    };
}



#endif //DOODLEJUMP_PLAYERMODEL_H
