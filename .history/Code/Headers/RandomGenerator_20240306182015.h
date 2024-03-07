#pragma once

#include <iostream>
#include <random>

#include "Cook.h"

class RandomGenerator
{
private:
    std::mt19937 generator;
    Cook cook;
public:
    RandomGenerator();
    RandomGenerator(int seed);
    ~RandomGenerator();

    /// @brief Function return random number within min, max - inclusive.
    /// @param min Min possible value
    /// @param max Max possible value
    /// @return Random number within boundaries
    int GetRandomNumber(int min, int max);
};
