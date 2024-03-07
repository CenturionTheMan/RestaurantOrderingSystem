#pragma once

#include "RandomGenerator.h"
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>

#include "PancakesTypes.h"

class Cook
{
private:
    RandomGenerator randomGenerator;
    PancakeType specializedInPancakeType;
    
    int maxCookingTimeMs;
    int minCookingTimeMs;
    int pancakesMaxAmount;

public:
    Cook(PancakeType pancakeTypeSpecialization, int pancakesMaxAmount, int minCookingTimeMs, int maxCookingTimeMs);
    ~Cook();

    void Run(std::vector<PancakeType>& buffet, std::mutex& mutex, std::condition_variable& conditionVariable);
};
