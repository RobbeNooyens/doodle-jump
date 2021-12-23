//
// Created by robbe on 20/11/2021.
//

#include "Random.h"

Random &Random::getInstance() {
    static Random INSTANCE;
    return INSTANCE;
}

Random::Random(): mt(rd()), zeroToOne() {};
