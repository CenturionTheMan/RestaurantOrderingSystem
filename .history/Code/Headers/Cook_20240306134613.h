#pragma once

#include "RandomGenerator.h"
#include <vector>
#include <thread>
#include <mutex>
// #include "../Implementations/PancakesTypes.cpp"

class Cook
{
private:
    RandomGenerator randomGenerator;

    PancakeType specializedInPancakeType;
    int maxCookingTimeMs;
    int minCookingTimeMs;

    void CookLoop(std::vector<PancakeType>& buffet, std::mutex& mutex);
    
public:
    Cook(PancakeType pancakeTypeSpecialization, int minCookingTimeMs, int maxCookingTimeMs);
    ~Cook();

    std::thread Run(std::vector<PancakeType>& buffet, std::mutex& mutex);
};

