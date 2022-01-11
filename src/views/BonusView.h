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

#ifndef DOODLEJUMP_BONUSVIEW_H
#define DOODLEJUMP_BONUSVIEW_H

#include "EntityView.h"

namespace views {
    /**
    * @brief Represents the bonus entity rendering
    */
    class BonusView: public EntityView {
    public:
        /**
         * @brief Constructor
         */
        BonusView();
    };
}

#endif //DOODLEJUMP_BONUSVIEW_H
