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

    protected:
        explicit PlatformModel(std::shared_ptr<EntityController>& controller);
    };

    class StaticPlatform: public PlatformModel {
    public:
        explicit StaticPlatform(std::shared_ptr<EntityController> controller);
        void update(double elapsed) override;
    };

    class HorizontalPlatform: public PlatformModel {
    public:
        explicit HorizontalPlatform(std::shared_ptr<EntityController> controller);
        void update(double elapsed) override;

    private:
        Direction direction = RIGHT;
        const unsigned int screenWidth;
        double speed = 100;
    };

    class VerticalPlatform: public PlatformModel{
    public:
        explicit VerticalPlatform(std::shared_ptr<EntityController> controller);
        void update(double elapsed) override;
    private:
        Direction direction = UP;
        double speed = 100;
        double relativeY = 0;
        double distance = 200;
    };

    class TemporaryPlatform: public PlatformModel{
    public:
        explicit TemporaryPlatform(std::shared_ptr<EntityController> controller);
        void update(double elapsed) override;
    };
}


#endif //DOODLEJUMP_PLATFORMMODEL_H
