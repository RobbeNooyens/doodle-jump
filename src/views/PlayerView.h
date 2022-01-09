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

#ifndef DOODLEJUMP_PLAYERVIEW_H
#define DOODLEJUMP_PLAYERVIEW_H

#include "EntityView.h"
#include "../enums/Direction.h"

namespace views {
    class PlayerView: public EntityView {
    public:
        PlayerView();

        void updateDirections(Direction horizontal, Direction vertical);

    private:
        Direction horizontalDirection = LEFT;
        Direction verticalDirection = UP;

    };
}


#endif //DOODLEJUMP_PLAYERVIEW_H
