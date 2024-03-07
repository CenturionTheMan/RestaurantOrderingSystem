#pragma once


#include <vector>
#include <map>
#include <mutex>
#include <condition_variable>
#include "Cook.h"


class Manager
{
private:
    static std::condition_variable bananaPancakesLimitCondition;
    static std::condition_variable blueberryPancakesLimitCondition;
    static std::condition_variable chocolatePancakesLimitCondition;

    static std::map<PancakeType, int> pancakesLimits;

   

    std::vector<Cook> bananaCooks;
    // std::vector<Cook*> blueberryCooks;
    // std::vector<Cook*> chocolateCooks;

public:
    Manager(int bananaPancakesLimit, int blueberryPancakesLimit, int chocolatePancakesLimit);
    ~Manager();

    void CreateAndRunCook(std::vector<PancakeType>& buffet, std::mutex& mutex, std::condition_variable& conditionVariable, PancakeType cookSpecialization);

    static int GetPancakesLimit(PancakeType pancakeType);

    
};






