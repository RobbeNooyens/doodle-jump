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

#ifndef DOODLEJUMP_PLATFORMMODEL_H
#define DOODLEJUMP_PLATFORMMODEL_H

#include "EntityModel.h"
#include "../enums/Direction.h"

namespace models {
    /**
     * @brief Represents platform logic
     */
    class PlatformModel: public EntityModel {
    public:
        /**
         * @brief Virtual destructor
         */
        ~PlatformModel() override = default;

        /**
         * @brief Update model based on the elapsed time
         * @param elapsed elapsed seconds since last frame
         */
        void update(double elapsed) override = 0;
        /**
         * @return true if platform will stay beneath the screen for the rest of the game
         */
        virtual bool isBeneathScreen();

    protected:
        /**
         * @brief Constructor
         */
        PlatformModel();
    };

    /**
     * @brief Represents static platform logic
     */
    class StaticPlatform: public PlatformModel {
    public:
        /**
         * @brief Constructor
         */
        StaticPlatform();

        /**
         * @brief Update model based on the elapsed time
         * @param elapsed elapsed seconds since last frame
         */
        void update(double elapsed) override;
    };

    /**
     * @brief Represents horizontal platform logic
     */
    class HorizontalPlatform: public PlatformModel {
    public:
        /**
         * @brief Constructor
         */
        HorizontalPlatform();

        /**
         * @brief Update model based on the elapsed time
         * @param elapsed elapsed seconds since last frame
         */
        void update(double elapsed) override;

    private:
        Direction direction = RIGHT;
        const unsigned int screenWidth;
        double speed = 100;
    };

    /**
     * @brief Represents vertical platform logic
     */
    class VerticalPlatform: public PlatformModel{
    public:
        /**
         * @brief Constructor
         */
        VerticalPlatform();

        /**
         * @brief Update model based on the elapsed time
         * @param elapsed elapsed seconds since last frame
         */
        void update(double elapsed) override;
        /**
         * @return true if platform will stay beneath the screen for the rest of the game
         */
        bool isBeneathScreen() override;
    private:
        Direction direction = UP;
        double speed = 100;
        double relativeY = 0;
        double distance = 200;
    };

    /**
     * @brief Represents temporary platform logic
     */
    class TemporaryPlatform: public PlatformModel{
    public:
        /**
         * @brief Constructor
         */
        TemporaryPlatform();

        /**
         * @brief Update model based on the elapsed time
         * @param elapsed elapsed seconds since last frame
         */
        void update(double elapsed) override;
    };
}


#endif //DOODLEJUMP_PLATFORMMODEL_H
