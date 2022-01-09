//
// Created by robnoo on 25/11/21.
//ev

#ifndef DOODLEJUMP_PLATFORMMODEL_H
#define DOODLEJUMP_PLATFORMMODEL_H

#include "EntityModel.h"
#include "../enums/Direction.h"

namespace models {
    class PlatformModel: public EntityModel {
    public:
        void update(double elapsed) override = 0;
        virtual bool isBeneathScreen();

    protected:
        PlatformModel();
    };

    class StaticPlatform: public PlatformModel {
    public:
        StaticPlatform();
        void update(double elapsed) override;
    };

    class HorizontalPlatform: public PlatformModel {
    public:
        HorizontalPlatform();
        void update(double elapsed) override;

    private:
        Direction direction = RIGHT;
        const unsigned int screenWidth;
        double speed = 100;
    };

    class VerticalPlatform: public PlatformModel{
    public:
        VerticalPlatform();
        void update(double elapsed) override;
        bool isBeneathScreen() override;
    private:
        Direction direction = UP;
        double speed = 100;
        double relativeY = 0;
        double distance = 200;
    };

    class TemporaryPlatform: public PlatformModel{
    public:
        TemporaryPlatform();
        void update(double elapsed) override;
    };
}


#endif //DOODLEJUMP_PLATFORMMODEL_H
