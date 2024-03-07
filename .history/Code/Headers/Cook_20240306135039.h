#pragma once
#ifndef COOK_H
#define COOK_H

#include "RandomGenerator.h"
#include <vector>
#include <thread>
#include <mutex>
#include "PancakesTypes.h"

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

#endif // COOK_H