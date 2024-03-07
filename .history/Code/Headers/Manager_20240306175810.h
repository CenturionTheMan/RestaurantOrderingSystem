#pragma once

#include <vector>
#include <map>
#include <mutex>
#include "Cook.h"

class Manager
{
private:
    

    static std::map<PancakeType, int> pancakesLimits;

public:
    std::condition_variable bananaPancakesLimitCondition;
    std::condition_variable blueberryPancakesLimitCondition;
    std::condition_variable chocolatePancakesLimitCondition;
    
    Manager(int bananaPancakesLimit, int blueberryPancakesLimit, int chocolatePancakesLimit);
    ~Manager();

    void CreateAndRunCook(std::vector<PancakeType>& buffet, std::mutex& mutex, std::condition_variable& conditionVariable, PancakeType cookSpecialization);

    std::condition_variable& GetPancakesLimitCondition(PancakeType pancakeType);
    
    static int GetPancakesLimit(PancakeType pancakeType);

    
};






