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

#ifndef DOODLEJUMP_PLAYERUSESBONUSEVENT_H
#define DOODLEJUMP_PLAYERUSESBONUSEVENT_H


#include "Event.h"
#include "../enums/BonusType.h"

namespace events {

    /**
     * @brief Represents an event when a player uses a bonus
     */
    class PlayerUsesBonusEvent : public Event {
    public:
        /**
         * @brief Default constructor
         * @param type bonus type
         * @param surfaceHeight y value of the bonus top
         * @param bonusId id of the bonus being used
         */
        PlayerUsesBonusEvent(BonusType type, double surfaceHeight, long bonusId);

        /**
         * @return bonus type
         */
        BonusType getBonusType();
        /**
         * @return y value of bonus top
         */
        [[nodiscard]] double getSurfaceHeight() const;
        /**
         * @return bonus entity id
         */
        [[nodiscard]] long getBonusEntityId() const;

    private:
        BonusType bonusType = BonusType::SPRING;
        double surfaceHeight = 0;
        long bonusId = 0;

    };

}


#endif //DOODLEJUMP_PLAYERUSESBONUSEVENT_H
