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

#ifndef DOODLEJUMP_PLAYERCONTROLLER_H
#define DOODLEJUMP_PLAYERCONTROLLER_H

#include <memory>
#include "EntityController.h"

class Event;

namespace controllers {
    class PlayerController: public EntityController {
    public:
        // Constructor
        PlayerController();

        // Actions
        void handle(std::shared_ptr<events::Event>& event) override;
        void update(double elapsed) override;
        void goesBeneathScreen() override;

    };
}


#endif //DOODLEJUMP_PLAYERCONTROLLER_H
