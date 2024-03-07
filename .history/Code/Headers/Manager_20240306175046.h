#pragma once

#include <vector>
#include <map>
#include <mutex>
#include "Cook.h"

class Manager
{
private:
    static std::map<PancakeType, std::condition_variable> pancakesLimitConditions;
    static std::map<PancakeType, int> PancakesLimits;

public:

    Manager(int bananaPancakesLimit, int blueberryPancakesLimit, int chocolatePancakesLimit);
    ~Manager();

    void CreateAndRunCook(std::vector<PancakeType>& buffet, std::mutex& mutex, std::condition_variable& conditionVariable, PancakeType cookSpecialization);

    static int GetPancakesLimit(PancakeType pancakeType);
};






