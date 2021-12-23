//
// Created by robbe on 20/11/2021.
//

#ifndef DOODLEJUMP_RANDOM_H
#define DOODLEJUMP_RANDOM_H

#include <map>
#include <cassert>
#include "../ScoreManager.h"

class Random {
public:
    static Random& getInstance();

    template<typename T>
    T randomWeighted(std::map<double, T> weightMap) {
        double sum = 0;
        for(auto& entry: weightMap) {
            sum += entry.first;
        }
        auto random = generate<double>(sum);
        double checkSum = 0;
        for(auto& entry: weightMap) {
            checkSum += entry.first;
            if(random <= checkSum)
                return entry.second;
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
        std::srand(ScoreManager::getInstance().getScore());
        T result = (T) ((rand()%1000)/1000.0);
        result *= (upperbound - lowerbound);
        result += lowerbound;
        return result;
    }

    Random(Random()) = delete;
    void operator=(Random const&) = delete;

private:
    Random();

};


#endif //DOODLEJUMP_RANDOM_H
