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

    static std::map<PancakeType, int> pancakesLimits;
    static int ingredientAmount;


    std::vector<Cook*> bananaCooks;
    std::vector<Cook*> blueberryCooks;
    std::vector<Cook*> chocolateCooks;

public:
    Manager(int bananaPancakesLimit, int blueberryPancakesLimit, int chocolatePancakesLimit);
    ~Manager();

    void CreateAndRunCook(std::map<PancakeType, int>& buffet, std::mutex& mutex, PancakeType cookSpecialization);

    static int GetPancakesLimit(PancakeType pancakeType);

    
};






