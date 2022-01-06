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

template<typename T>
T Stopwatch::elapsed() {
    return (T) (getCurrentTime() - begin).count();
}

template<typename T>
T Stopwatch::elapsedNanoseconds() {
    return (T) std::chrono::duration_cast<std::chrono::nanoseconds>(getCurrentTime() - begin).count();
}
