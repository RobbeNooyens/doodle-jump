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

#ifndef DOODLEJUMP_BONUSMODEL_H
#define DOODLEJUMP_BONUSMODEL_H

#include "EntityModel.h"
#include "PlatformModel.h"

namespace models {
    /**
     * @brief Represents bonus logic
     */
    class BonusModel: public EntityModel {
    public:
        /**
         * @brief Virtual destructor
         */
        virtual ~BonusModel() = default;

        /**
         * @brief Update model based on the elapsed time
         * @param elapsed elapsed seconds since last frame
         */
        void update(double elapsed) override;

    protected:
        /**
         * @brief Constructor
         */
        BonusModel();
    };

    /**
     * @brief Represents spring logic
     */
    class SpringModel: public BonusModel {
    public:
        /**
         * @brief Constructor
         */
        SpringModel();
    };

    /**
     * @brief Represents jetpack logic
     */
    class JetpackModel: public BonusModel {
    public:
        /**
         * @brief Constructor
         */
        JetpackModel();
    };
}

#endif //DOODLEJUMP_BONUSMODEL_H
