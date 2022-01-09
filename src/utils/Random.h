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

#ifndef DOODLEJUMP_RANDOM_H
#define DOODLEJUMP_RANDOM_H

#include <map>
#include <cassert>
#include <random>
#include <stdexcept>
#include "../exceptions/UndefinedException.h"

/**
 * @brief Singleton that generates random numbers
 */
class Random {
public:
    /**
     * @return Singleton instance of Random
     */
    static Random& getInstance();

    /**
     * @brief Choose random element from a map with weights
     * @tparam T random element type
     * @param weightMap map with an element and its weight
     * @return a weighted random element from the input map
     */
    template<typename T>
    T randomWeighted(std::map<T, double> weightMap) {
        double sum = 0;
        for(auto& entry: weightMap) {
            sum += entry.second;
        }
        auto random = generate<double>(sum);
        double checkSum = 0;
        for(auto& entry: weightMap) {
            checkSum += entry.second;
            if(random <= checkSum)
                return entry.first;
        }
        throw exceptions::UndefinedException("Reached an unreachable statement");
    }

    /**
     * @brief Generates random number between 0 and 1
     * @tparam T number type
     * @return random number of type T between 0 and 1
     */
    template<typename T>
    T generate() {
        return generate((T) 1);
    }

    template<typename T>
    /**
     * @brief Generates random number between 0 and upperbound
     * @tparam T number type
     * @param upperbound upperbound for random number
     * @return random number between 0 and upperbound
     */
    T generate(T upperbound) {
        return generate((T) 0, upperbound);
    }

    /**
     * @brief Generates random number between lowerbound and upperbound
     * @tparam T number type
     * @param lowerbound lowerbound for random number
     * @param upperbound upperbound for random number
     * @return random number between lowerbound and upperbound
     */
    template<typename T>
    T generate(T lowerbound, T upperbound) {
        assert(lowerbound <= upperbound && "Lowerbound must be smaller than the upperbound.");
        return (T) (zeroToOne(mt) * (upperbound - lowerbound) + lowerbound);
    }

    Random(Random()) = delete;
    void operator=(Random const&) = delete;

private:
    Random();

    std::random_device rd;
    std::mt19937 mt;
    std::uniform_real_distribution<double> zeroToOne;

};


#endif //DOODLEJUMP_RANDOM_H
