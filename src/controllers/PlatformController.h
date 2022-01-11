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

#ifndef DOODLEJUMP_PLATFORMCONTROLLER_H
#define DOODLEJUMP_PLATFORMCONTROLLER_H

#include <memory>
#include "EntityController.h"
#include "../enums/PlatformType.h"

namespace controllers {

    class BonusController;

    /**
     * @brief Represents a platform entity
     */
    class PlatformController: public EntityController {
    public:
        // Constructor
        /**
         * @brief Parameter constructor
         * @param type enum value representing the type of platform
         */
        explicit PlatformController(PlatformType type);

        // Actions
        /**
         * @brief Handles incoming game events
         * @param event event that got invoked
         */
        void handle(std::shared_ptr<events::Event> &event) override;
        /**
         * @brief Performs actions when the entity goes below the bottom screenedge
         */
        void goesBeneathScreen() override;

        // Getters
        /**
         * @return enum representing the platform type
         */
        PlatformType getType();
        /**
         * @return true if the platform will never be visible again
         */
        bool isBeneathScreen();

        // Setters
        /**
         * @param bonusController bonus thats stands on this platform
         */
        void setBonus(std::shared_ptr<BonusController>& bonusController);

    private:
        std::weak_ptr<BonusController> bonus{};
        PlatformType platformType = PlatformType::STATIC;
        int jumpCount = 0;
    };

    /**
     * @brief Represents a static platform entity
     */
    class StaticPlatformController: public PlatformController {
    public:
        /**
         * @brief Default constructor
         */
        StaticPlatformController();
    };

    /**
     * @brief Represents a temporary platform entity
     */
    class TemporaryPlatformController: public PlatformController {
    public:
        /**
         * @brief Default constructor
         */
        TemporaryPlatformController();
    };

    /**
     * @brief Represents a horizontal platform entity
     */
    class HorizontalPlatformController: public PlatformController {
    public:
        /**
         * @brief Default constructor
         */
        HorizontalPlatformController();
    };

    /**
     * @brief Represents a vertical platfrom
     */
    class VerticalPlatformController: public PlatformController {
    public:
        /**
         * Default constructor
         */
        VerticalPlatformController();
    };
}


#endif //DOODLEJUMP_PLATFORMCONTROLLER_H
