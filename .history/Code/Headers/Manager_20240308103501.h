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
    int ingredientsAddAmount = 10;
    
    std::condition_variable bananaPancakesLimitCondition;
    std::condition_variable blueberryPancakesLimitCondition;
    std::condition_variable chocolatePancakesLimitCondition;


    std::vector<Cook*> bananaCooks;
    std::vector<Cook*> blueberryCooks;
    std::vector<Cook*> chocolateCooks;

public:
    Manager();
    ~Manager();

    void CreateAndRunCook(PancakeType cookSpecialization);

    void RunManager();

};






