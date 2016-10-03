//
// Created by michael on 10/3/16.
//

#ifndef MESSAGE_GENERATOR_UNIFORMRANDOM_H
#define MESSAGE_GENERATOR_UNIFORMRANDOM_H

#include <random>

class UniformRandom {
public:
    explicit UniformRandom(int seed, int min, int max);
    int next();

private:
    std::uniform_int_distribution<int> m_dist;
    std::default_random_engine m_engine;
};


#endif //MESSAGE_GENERATOR_UNIFORMRANDOM_H
