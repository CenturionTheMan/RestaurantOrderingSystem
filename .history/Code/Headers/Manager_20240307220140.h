#pragma once


#include <vector>
#include <map>
#include <mutex>
#include <condition_variable>
#include "PancakesTypes.h"
#include "Cook.h"

class Cook;

class Manager
{
private:
    static std::condition_variable bananaPancakesLimitCondition;
    static std::condition_variable blueberryPancakesLimitCondition;
    static std::condition_variable chocolatePancakesLimitCondition;
    static std::condition_variable fridgeConditionVariable;

    static std::map<PancakeType, int> pancakesLimits;

    std::vector<Cook*> bananaCooks;
    std::vector<Cook*> blueberryCooks;
    std::vector<Cook*> chocolateCooks;

public:
    Manager(int bananaPancakesLimit, int blueberryPancakesLimit, int chocolatePancakesLimit);
    ~Manager();

    void CreateAndRunCook(PancakeType cookSpecialization);

    void RunManager();

    static int GetPancakesLimit(PancakeType pancakeType);
};






