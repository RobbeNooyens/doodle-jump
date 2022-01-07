//
// Created by robbe on 20/11/2021.
//

#ifndef DOODLEJUMP_STOPWATCH_H
#define DOODLEJUMP_STOPWATCH_H

#include <chrono>

using TimeStamp = std::chrono::system_clock::time_point;

class Stopwatch {
public:
    // Singleton specific
    static Stopwatch& getInstance();
    Stopwatch(Stopwatch()) = delete;
    void operator=(Stopwatch const&) = delete;

    // Actions
    void reset();

    // Getters
    template<typename T>
    T elapsed() {
        return (T) (getCurrentTime() - begin).count();
    }

    template<typename T>
    T elapsedNanoseconds() {
        return (T) std::chrono::duration_cast<std::chrono::nanoseconds>(getCurrentTime() - begin).count();
    }

private:
    static TimeStamp getCurrentTime();

    Stopwatch();

    TimeStamp begin;
};


#endif //DOODLEJUMP_STOPWATCH_H
