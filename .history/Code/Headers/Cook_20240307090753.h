#pragma once

#include <thread>
#include <mutex>
#include <condition_variable>

#include "RandomGenerator.h"
#include "PancakesTypes.h"
#include "Manager.h"
#include "RestaurantContainers.h"

class Cook
{
private:
    RandomGenerator randomGenerator;
    PancakeType specializedInPancakeType;

    int maxCookingTimeMs;
    int minCookingTimeMs;

    bool shouldAbort = false;

public:
    Cook(PancakeType pancakeTypeSpecialization, int minCookingTimeMs, int maxCookingTimeMs);
    ~Cook();

    void Run(std::condition_variable& conditionVariable);
};
