#pragma once


#include <vector>
#include <map>
#include <mutex>
#include <condition_variable>
#include <thread>
#include "PancakesTypes.h"
#include "RestaurantContainers.h"
#include "EntityEnums.h"




class Manager
{
private:

    /// @brief amount of ingredients that will be added to the fridge
    int ingredientsAddAmount;

    ManagerState state;

public:

    /// @brief condition variables that the manager will use to wake up the specific cooks
    std::condition_variable BananaPancakesLimitCondition;
    std::condition_variable BlueberryPancakesLimitCondition;
    std::condition_variable ChocolatePancakesLimitCondition;
    ///

    /// @brief Construct a new Manager object
    /// @param ingredientsAddAmount amount of ingredients that will be added to the fridge
    Manager(int ingredientsAddAmount);

    /// @brief Destroy the Manager object
    ~Manager();

    /// @brief method that starts the manager thread
    void Run();

    /// @brief returns the state of the manager
    ManagerState GetState() { return state; }

};






