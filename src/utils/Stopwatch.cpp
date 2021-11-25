//
// Created by robbe on 20/11/2021.
//

#include "Stopwatch.h"

doodlejump::Stopwatch &doodlejump::Stopwatch::getInstance() {
    static Stopwatch INSTANCE;
    return INSTANCE;
}

void doodlejump::Stopwatch::start() {

}

void doodlejump::Stopwatch::stop() {

}

void doodlejump::Stopwatch::reset() {

}

double doodlejump::Stopwatch::elapsedSeconds() {
    return 0;
}

doodlejump::Stopwatch::Stopwatch() = default;
