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

class Random {
public:
    static Random& getInstance();

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
        throw std::runtime_error("Cant reach this");
    }

    template<typename T>
    T generate() {
        return generate((T) 1);
    }

    template<typename T>
    T generate(T upperbound) {
        return generate((T) 0, upperbound);
    }

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
