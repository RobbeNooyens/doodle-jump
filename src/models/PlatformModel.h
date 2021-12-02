//
// Created by robnoo on 25/11/21.
//

#ifndef DOODLEJUMP_PLATFORMMODEL_H
#define DOODLEJUMP_PLATFORMMODEL_H

#include "EntityModel.h"

namespace models {
    class PlatformModel: public EntityModel {
    public:
        PlatformModel();
        void update(double elapsed) override = 0;
    };

    class HorizontalPlatform: public PlatformModel {
    public:
        void update(double elapsed) override;

    private:
        double speed = 5;
    };

    class VerticalPlatform: public PlatformModel{
    public:
        void update(double elapsed) override;
    private:
        double speed = 5;
    };

    class TemporaryPlatform: public PlatformModel{
    public:
        void update(double elapsed) override;
    };
}


#endif //DOODLEJUMP_PLATFORMMODEL_H
