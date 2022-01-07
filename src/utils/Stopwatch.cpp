//
// Created by robbe on 20/11/2021.
//

#define MILLISECONDS

#include "Stopwatch.h"

Stopwatch &Stopwatch::getInstance() {
    static Stopwatch INSTANCE;
    return INSTANCE;
}

void Stopwatch::reset() {
    begin = getCurrentTime();
}

Stopwatch::Stopwatch(): begin(getCurrentTime()) {}

TimeStamp Stopwatch::getCurrentTime() {
    return std::chrono::system_clock::now();
}
