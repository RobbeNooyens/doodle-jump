/**
 *  ╒══════════════════════════════════════╕
 *  │                                      │
 *  │             Doodle Jump              │
 *  │        Advanced Programming          │
 *  │                                      │
 *  │            Robbe Nooyens             │
 *  │    s0201010@student.uantwerpen.be    │
 *  │                                      │
 *  │        University of Antwerp         │
 *  │                                      │
 *  ╘══════════════════════════════════════╛
 */

#ifndef DOODLEJUMP_TILEMODEL_H
#define DOODLEJUMP_TILEMODEL_H

#include "EntityModel.h"

namespace models {
    class TileModel: public EntityModel {
    public:
        TileModel();

        void update(double elapsed) override;

        void recycle();
    };
}


#endif //DOODLEJUMP_TILEMODEL_H
