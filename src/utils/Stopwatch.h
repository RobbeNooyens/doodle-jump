//
// Created by robbe on 20/11/2021.
//

#ifndef DOODLEJUMP_STOPWATCH_H
#define DOODLEJUMP_STOPWATCH_H

#include <chrono>

namespace doodlejump {
    class Stopwatch {
    public:
        static Stopwatch& getInstance();

        void start();

        void stop();

        void reset();

        double elapsedSeconds();

    private:
        Stopwatch();

        std::chrono::system_clock::time_point begin;

        bool running = false;


    };
}


#endif //DOODLEJUMP_STOPWATCH_H
