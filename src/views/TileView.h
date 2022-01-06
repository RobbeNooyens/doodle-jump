//
// Created by robnoo on 25/11/21.
//

#ifndef DOODLEJUMP_TILEVIEW_H
#define DOODLEJUMP_TILEVIEW_H

#include "EntityView.h"

namespace views {
    class TileView: public EntityView {
    public:
        explicit TileView(std::shared_ptr<EntityController> controller);
    };
}


#endif //DOODLEJUMP_TILEVIEW_H
