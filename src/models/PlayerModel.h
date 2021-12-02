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
        double getX();
        double getY();
        void setSize(double size);
        void moveTo(double x, double y);

    private:
        double x = 0, y = 0;
        double energie = 0;
        double highest = 0;
        double size;
        PlayerState state;
        BoundingBox bbox;

    };
}



#endif //DOODLEJUMP_PLAYERMODEL_H
