//
// Created by robnoo on 25/11/21.
//

#ifndef DOODLEJUMP_TILECONTROLLER_H
#define DOODLEJUMP_TILECONTROLLER_H

#include "EntityController.h"

namespace controllers {
    class TileController: public EntityController {
    public:
        TileController();

        void handle(std::shared_ptr<events::Event> &event) override;

        void recycle();
    };
}


#endif //DOODLEJUMP_TILECONTROLLER_H
