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

#ifndef DOODLEJUMP_STOPWATCH_H
#define DOODLEJUMP_STOPWATCH_H

#include <chrono>

using TimeStamp = std::chrono::system_clock::time_point;

/**
 * @brief Singleton that can be used to manage elapsed time per frame
 */
class Stopwatch {
public:
    // Singleton specific
    /**
     * @return static singleton instance of stopwatch
     */
    static Stopwatch& getInstance();

    Stopwatch(Stopwatch()) = delete;
    void operator=(Stopwatch const&) = delete;

    // Actions
    /**
     * @brief Resets the start timestamp to the current timestamp
     */
    void reset();

    // Getters
    /**
     * @brief Calculates the time elapsed since start timings
     * @tparam T number type
     * @return time elapsed since begin
     */
    template<typename T>
    T elapsed() {
        return (T) (getCurrentTime() - begin).count();
    }

    /**
     * @brief Calculates nanoseconds since start timings
     * @tparam T number type
     * @return nanoseconds since begin
     */
    template<typename T>
    T elapsedNanoseconds() {
        return (T) std::chrono::duration_cast<std::chrono::nanoseconds>(getCurrentTime() - begin).count();
    }

private:
    static TimeStamp getCurrentTime();

    Stopwatch();

    TimeStamp begin{};
};


#endif //DOODLEJUMP_STOPWATCH_H
