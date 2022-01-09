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
    /**
     * @brief Represents the entity rendering
     */
    class PlayerView: public EntityView {
    public:
        /**
         * @brief Constructor
         */
        PlayerView();

        /**
         * @brief Updates directions to apply the right texture
         * @param horizontal horizontal direction left or right
         * @param vertical vertical direction up or down
         */
        void updateDirections(Direction horizontal, Direction vertical);

    private:
        Direction horizontalDirection = LEFT;
        Direction verticalDirection = UP;

    };
}


#endif //DOODLEJUMP_PLAYERVIEW_H
