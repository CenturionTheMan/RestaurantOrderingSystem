#pragma once


#include <vector>
#include <map>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <thread>
#include "PancakesTypes.h"
#include "RestaurantContainers.h"


class Manager
{
private:
    int ingredientsAddAmount = 10;

public:
    std::condition_variable BananaPancakesLimitCondition;
    std::condition_variable BlueberryPancakesLimitCondition;
    std::condition_variable ChocolatePancakesLimitCondition;

    Manager();
    ~Manager();

    // void CreateAndRunCook(PancakeType cookSpecialization);

    void Run();

};






