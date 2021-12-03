//
// Created by robbe on 20/11/2021.
//

#define MILLISECONDS

#include "Stopwatch.h"

Stopwatch &Stopwatch::getInstance() {
    static Stopwatch INSTANCE;
    return INSTANCE;
}

void Stopwatch::start() {
    running = true;
}

void Stopwatch::stop() {
    running = false;
    end = getCurrentTime();
}

void Stopwatch::reset() {
    begin = getCurrentTime();
    end = getCurrentTime();
    beginCycle = getCurrentTime();
}

double Stopwatch::elapsedSeconds() {
    return (double) std::chrono::duration_cast<std::chrono::seconds>((running ? getCurrentTime() : end) - begin).count();
}

double Stopwatch::elapsed() {
    return (double) ((running ? getCurrentTime() : end) - begin).count();
}

Stopwatch::Stopwatch(): begin(getCurrentTime()), end(getCurrentTime()) {}

TimeStamp Stopwatch::getCurrentTime() {
    return std::chrono::system_clock::now();
}

double Stopwatch::elapsedSinceLastCycle() {
    return (double) ((running ? getCurrentTime() : end) - beginCycle).count();
}

void Stopwatch::startCycle() {
    beginCycle = getCurrentTime();
}

double Stopwatch::elapsedMillisecondsSinceLastCycle() {
    return (double) std::chrono::duration_cast<std::chrono::nanoseconds>((running ? getCurrentTime() : end) - beginCycle).count();
}
