//
// Created by robnoo on 4/12/21.
//

#ifndef DOODLEJUMP_WORLDGENERATOR_H
#define DOODLEJUMP_WORLDGENERATOR_H


#include "events/EventHandler.h"

class WorldGenerator {
public:
    void update();

private:
    double previousHeight;
};


#endif //DOODLEJUMP_WORLDGENERATOR_H
