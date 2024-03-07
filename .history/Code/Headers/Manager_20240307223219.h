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
    int ingredientsLowerLimit = 10;

    static std::condition_variable bananaPancakesLimitCondition;
    static std::condition_variable blueberryPancakesLimitCondition;
    static std::condition_variable chocolatePancakesLimitCondition;
    static std::condition_variable fridgeConditionVariable;


    std::vector<Cook*> bananaCooks;
    std::vector<Cook*> blueberryCooks;
    std::vector<Cook*> chocolateCooks;

public:
    Manager();
    ~Manager();

    void CreateAndRunCook(PancakeType cookSpecialization);

    void RunManager();

};






