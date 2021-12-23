//
// Created by robbe on 20/11/2021.
//

#ifndef DOODLEJUMP_STOPWATCH_H
#define DOODLEJUMP_STOPWATCH_H

#include <chrono>

using TimeStamp = std::chrono::system_clock::time_point;

class Stopwatch {
public:
    static Stopwatch& getInstance();

    void reset();

    double elapsed();
    double elapsedNanoseconds();

    Stopwatch(Stopwatch()) = delete;
    void operator=(Stopwatch const&) = delete;
private:
    static TimeStamp getCurrentTime();
    Stopwatch();

    TimeStamp begin;
};


#endif //DOODLEJUMP_STOPWATCH_H
