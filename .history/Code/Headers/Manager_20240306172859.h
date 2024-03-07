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
public:
    static std::map<PancakeType, int> PancakesLimits;

    Manager(/* args */);
    ~Manager();

    void CreateAndRunCook(std::vector<PancakeType>& buffet, std::mutex& mutex, std::condition_variable& conditionVariable, PancakeType cookSpecialization);

};






