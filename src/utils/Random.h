//
// Created by robbe on 20/11/2021.
//

#ifndef DOODLEJUMP_RANDOM_H
#define DOODLEJUMP_RANDOM_H

class Random {
public:
    static Random& getInstance();

    double generate();
    double generate(double upperbound);
    double generate(double lowerbound, double upperbound);

private:
    Random();

};


#endif //DOODLEJUMP_RANDOM_H
