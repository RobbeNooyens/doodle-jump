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
    /**
     * @brief Represents a player entity
     */
    class PlayerController: public EntityController {
    public:
        // Constructor
        /**
         * @brief Default constructor
         */
        PlayerController();

        // Actions
        /**
         * @brief Handles incoming game events
         * @param event event that got invoked
         */
        void handle(std::shared_ptr<events::Event>& event) override;
        /**
         * @brief Updates state based on elapsed seconds
         * @param elapsed seconds since last frame
         */
        void update(double elapsed) override;
        /**
         * @brief Performs actions when the entity goes below the bottom screenedge
         */
        void goesBeneathScreen() override;

    };
}


#endif //DOODLEJUMP_PLAYERCONTROLLER_H
