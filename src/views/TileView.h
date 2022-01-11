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

#ifndef DOODLEJUMP_TILEVIEW_H
#define DOODLEJUMP_TILEVIEW_H

#include "EntityView.h"

namespace views {
    /**
     * @brief Represents the entity rendering
     */
    class TileView: public EntityView {
    public:
        /**
         * @brief Constructor
         */
        TileView();
    };
}


#endif //DOODLEJUMP_TILEVIEW_H
