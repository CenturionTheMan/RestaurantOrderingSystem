#pragma once

#include <random>

class RandomGenerator
{
private:
    /// @brief random number generator
    std::mt19937 generator;
public:
    /// @brief Construct a new Random Generator object (will use random seed)
    RandomGenerator();

    /// @brief Construct a new Random Generator object
    /// @param seed seed for the random number generator
    RandomGenerator(int seed);

    /// @brief Destroy the Random Generator object
    ~RandomGenerator();

    /// @brief Function return random number within min, max - inclusive.
    /// @param min Min possible value
    /// @param max Max possible value
    /// @return Random number within boundaries
    int GetRandomNumber(int min, int max);
};
