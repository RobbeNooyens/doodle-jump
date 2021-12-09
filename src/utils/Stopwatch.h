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

    void start();

    void stop();

    void reset();

    void startCycle();

    double elapsedSeconds();

    double elapsed();

    double elapsedSinceLastCycle();
    double elapsedMillisecondsSinceLastCycle();

    Stopwatch(Stopwatch()) = delete;
    void operator=(Stopwatch const&) = delete;
private:
    static TimeStamp getCurrentTime();

    Stopwatch();
    TimeStamp begin;

    TimeStamp end;

    TimeStamp beginCycle;


    bool running = false;
};


#endif //DOODLEJUMP_STOPWATCH_H
