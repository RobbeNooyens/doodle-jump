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
    /**
     * @brief Represents tile logic
     */
    class TileModel: public EntityModel {
    public:
        /**
         * @brief Constructor
         */
        TileModel();

        /**
         * @brief Update model based on the elapsed time
         * @param elapsed elapsed seconds since last frame
         */
        void update(double elapsed) override;

        /**
         * @brief move tile above upper screen border to continue scrolling effect
         */
        void recycle();
    };
}


#endif //DOODLEJUMP_TILEMODEL_H
