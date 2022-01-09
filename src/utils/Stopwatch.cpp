/**
 *  ╒══════════════════════════════════════╕
 *  │                                      │
 *  │             Doodle Jump              │
 *  │        Advanced Programming          │
 *  │                                      │
 *  │            Robbe Nooyens             │
 *  │    s0201010@student.uantwerpen.be    │
 *  │                                      │
 *  │        University of Antwerp         │
 *  │                                      │
 *  ╘══════════════════════════════════════╛
 */

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
