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

    void CookLoop(std::vector<PancakeType>& buffet, std::mutex& mutex, std::condition_variable& conditionVariable);
    
public:
    Cook(PancakeType pancakeTypeSpecialization, int minCookingTimeMs, int maxCookingTimeMs);
    ~Cook();

    std::thread Run(std::vector<PancakeType>& buffet, std::mutex& mutex, std::condition_variable& conditionVariable);
};
