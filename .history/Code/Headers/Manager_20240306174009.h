#pragma once

#include <vector>
#include <map>
#include <mutex>
#include "Cook.h"

class Manager
{
private:
    std::condition_variable bananaPancakesLimitCondition;
    std::condition_variable blueberryPancakesLimitCondition;
    std::condition_variable chocolatePancakesLimitCondition;
    std::map<PancakeType, int> PancakesLimits;

public:

    Manager(int bananaPancakesLimit, int blueberryPancakesLimit, int chocolatePancakesLimit);
    ~Manager();

    void CreateAndRunCook(std::vector<PancakeType>& buffet, std::mutex& mutex, std::condition_variable& conditionVariable, PancakeType cookSpecialization);

    static int GetPancakesLimit(PancakeType pancakeType);
};






