#pragma once


#include <vector>
#include <map>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include "PancakesTypes.h"
#include "RestaurantContainers.h"

class Cook;

class Manager
{
private:
    int ingredientsAddAmount = 10;

public:
    std::condition_variable bananaPancakesLimitCondition;
    std::condition_variable blueberryPancakesLimitCondition;
    std::condition_variable chocolatePancakesLimitCondition;

    Manager();
    ~Manager();

    // void CreateAndRunCook(PancakeType cookSpecialization);

    void RunManager();

};






