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

#ifndef DOODLEJUMP_TILECONTROLLER_H
#define DOODLEJUMP_TILECONTROLLER_H

#include "EntityController.h"

namespace controllers {
    class TileController: public EntityController {
    public:
        TileController();

        void handle(std::shared_ptr<events::Event> &event) override;

        void goesBeneathScreen() override;
    };
}


#endif //DOODLEJUMP_TILECONTROLLER_H
