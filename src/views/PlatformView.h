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

#ifndef DOODLEJUMP_PLATFORMVIEW_H
#define DOODLEJUMP_PLATFORMVIEW_H

#include "EntityView.h"

namespace views {
    /**
     * @brief Represents the platform entity rendering
     */
    class PlatformView: public EntityView {
    public:
        /**
         * @brief Constructor
         */
        PlatformView();

    };
}

#endif //DOODLEJUMP_PLATFORMVIEW_H
