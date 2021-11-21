//
// Created by robbe on 20/11/2021.
//

#include <cstdlib>
#include <ctime>
#include <cassert>
#include "Random.h"

double doodlejump::Random::generate() {
    return generate(1);
}

double doodlejump::Random::generate(double upperbound) {
    return generate(0, upperbound);
}

double doodlejump::Random::generate(double lowerbound, double upperbound) {
    assert(lowerbound <= upperbound && "Lowerbound must be smaller than the upperbound.");
    std::srand(time(nullptr));
    double result = (rand() % 10) + 1;
    result *= (upperbound - lowerbound);
    result += lowerbound;
    return result;
}
