//
// Created by robnoo on 25/11/21.
//

#ifndef DOODLEJUMP_PLAYERMODEL_H
#define DOODLEJUMP_PLAYERMODEL_H

#include "EntityModel.h"
#include "../utils/ResourceLoader.h"

enum PlayerState {FALLING, JUMPING, BOUNCING, FLYING};

namespace models {
    class PlayerModel: public EntityModel {
    public:
        PlayerModel();

        void update(double elapsed) override;

    private:
        const double jumpHeight = 7;
        const double acceleration = 4;
        double speed = 0;
        double highest = 0;
        double y0 = 0, t = 0, a = 0.5;
        PlayerState state = FALLING;


    };
}



#endif //DOODLEJUMP_PLAYERMODEL_H
