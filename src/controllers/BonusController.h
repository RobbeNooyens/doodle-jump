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

#ifndef DOODLEJUMP_BONUSCONTROLLER_H
#define DOODLEJUMP_BONUSCONTROLLER_H

#include "EntityController.h"
#include "../enums/BonusType.h"

namespace controllers {

    class PlatformController;

    /**
     * @brief Represent a bonus entity
     */
    class BonusController: public EntityController {
    public:
        // Constructor
        /**
         * @brief Parameter constructor
         * @param type enum value representing the type of this bonus
         */
        explicit BonusController(BonusType type);

        // Actions
        /**
         * @brief Handles incoming game events
         * @param event event that got invoked
         */
        void handle(std::shared_ptr<events::Event> &event) override;
        /**
         * @brief Updates state based on elapsed seconds
         * @param elapsed seconds since last frame
         */
        void update(double elapsed) override;
        /**
         * @brief Performs actions when the entity goes below the bottom screenedge
         */
        void goesBeneathScreen() override;

        // Setters
        /**
         * @param platformController platform the bonus stands on
         */
        void setPlatform(std::shared_ptr<controllers::PlatformController>& platformController);

        // Getters
        /**
         * @return enum representing the bonus type
         */
        BonusType getType();

    protected:
        /**
         * @brief Handles actions when the bonus has just been activated
         */
        virtual void use() = 0;

    private:
        double offset = 0;
        std::shared_ptr<PlatformController> platform;
        BonusType bonusType = BonusType::SPRING;
    };

    /**
     * @brief Represents a spring entity
     */
    class SpringController: public BonusController {
    public:
        /**
         * @brief Default constructor
         */
        SpringController();

    protected:
        /**
         * @brief Handles actions when the bonus has just been activated
         */
        void use() override;
    };

    class JetpackController: public BonusController {
    public:
        /**
         * @brief Default constructor
         */
        JetpackController();

    protected:
        /**
         * @brief Handles actions when the bonus has just been activated
         */
        void use() override;
    };
}


#endif //DOODLEJUMP_BONUSCONTROLLER_H
