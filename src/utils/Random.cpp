//
// Created by robbe on 20/11/2021.
//

#include <cstdlib>
#include <ctime>
#include <cassert>
#include "Random.h"
#include "../ScoreManager.h"

Random &Random::getInstance() {
    static Random INSTANCE;
    return INSTANCE;
}

Random::Random(): mt(rd()), zeroToOne((0, 1)) {};
