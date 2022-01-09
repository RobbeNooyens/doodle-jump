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

#ifndef DOODLEJUMP_PLAYERMODEL_H
#define DOODLEJUMP_PLAYERMODEL_H

#include "EntityModel.h"
#include "../enums/Direction.h"
#include "../enums/BonusType.h"

class TextureLoader;

namespace models {
    /**
     * @brief Represents player logic
     */
    class PlayerModel: public EntityModel {
    public:
        /**
         * @brief Constructor
         */
        PlayerModel();

        /**
         * @brief Update model based on the elapsed time
         * @param elapsed elapsed seconds since last frame
         */
        void update(double elapsed) override;

        /**
         * @brief Move over x axis
         * @param direction left or right
         */
        void moveHorizontal(Direction direction);
        /**
         * @brief Apply bonus effects
         * @param bonusType bonus type
         * @param surfaceHeight y value of top of bonus entity
         */
        void useBonus(BonusType bonusType, double surfaceHeight);
        /**
         * @brief Let player bounce on a platform
         * @param surfaceHeight y value of top of platform entity
         */
        void bounceOnPlatform(double surfaceHeight);

        /**
         * @return vertical direction up or down
         */
        Direction getVerticalDirection();
        /**
         * @return horizontal direction left or right
         */
        Direction getHorizontalDirection();

    private:
        double speed = 15, boost = 1;
        Direction verticalDirection = Direction::UP;
        Direction horizontalDirection = Direction::RIGHT;

        bool moveXAxis = false;

        void bounce(double from);
        void checkMaxHeight();
    };
}



#endif //DOODLEJUMP_PLAYERMODEL_H
