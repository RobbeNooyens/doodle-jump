//
// Created by robnoo on 25/11/21.
//

#ifndef DOODLEJUMP_TILEMODEL_H
#define DOODLEJUMP_TILEMODEL_H

#include "EntityModel.h"

namespace models {
    class TileModel: public EntityModel {
    public:
        TileModel();

        void update(double elapsed) override;
    };
}


#endif //DOODLEJUMP_TILEMODEL_H
