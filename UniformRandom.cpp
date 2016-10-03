//
// Created by michael on 10/3/16.
//

#include "UniformRandom.h"

UniformRandom::UniformRandom(int seed, int min, int max) : m_engine(seed), m_dist(min, max) {

}

int UniformRandom::next() {
    return m_dist(m_engine);
}
