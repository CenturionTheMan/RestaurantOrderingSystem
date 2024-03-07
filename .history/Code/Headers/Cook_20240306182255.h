#pragma once

#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include "RandomGenerator.h"

#include "PancakesTypes.h"
#include "Manager.h"

class Cook
{
private:
    RandomGenerator randomGenerator;
    PancakeType specializedInPancakeType;
    Manager manager;
    int maxCookingTimeMs;
    int minCookingTimeMs;
public:
    Cook(PancakeType pancakeTypeSpecialization, int minCookingTimeMs, int maxCookingTimeMs);
    ~Cook();

    void Run(std::vector<PancakeType>& buffet, std::mutex& mutex, std::condition_variable& conditionVariable);
};
