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
    /**
     * @brief Represents a background tile
     */
    class TileController: public EntityController {
    public:
        /**
         * @brief Default constructor
         */
        TileController();

        /**
         * @brief Handles incoming game events
         * @param event event that got invoked
         */
        void handle(std::shared_ptr<events::Event> &event) override;
        /**
         * @brief Performs actions when the entity goes below the bottom screenedge
         */
        void goesBeneathScreen() override;
    };
}


#endif //DOODLEJUMP_TILECONTROLLER_H
