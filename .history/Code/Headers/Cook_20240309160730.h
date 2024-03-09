#pragma once

#include <thread>
#include <mutex>
#include <condition_variable>

#include "RandomGenerator.h"
#include "PancakesTypes.h"
#include "Manager.h"
#include "RestaurantContainers.h"
#include "EntityEnums.h"





/// @brief Class that represents a cook that prepares pancakes
class Cook
{
private:
    /// @brief random generator used to generate random cooking time
    RandomGenerator randomGenerator;

    /// @brief current cook state
    CookState state;

    /// @brief type of pancake that the cook specializes in (makes)
    PancakeType specializedInPancakeType;

    /// @brief pointer to the condition variable that the cook will wait on (fridge and buffet)
    std::condition_variable* conditionVariable;

    /// @brief minimum and maximum cooking time in milliseconds
    int maxCookingTimeMs, minCookingTimeMs;

    bool isStopRequested = false;

public:
    /// @brief construct a new Cook object
    /// @param manager reference to the manager object
    /// @param pancakeTypeSpecialization type of pancake that the cook specializes in (makes) 
    /// @param minCookingTimeMs minimum cooking time in milliseconds
    /// @param maxCookingTimeMs maximum cooking time in milliseconds
    Cook(Manager& manager, PancakeType pancakeTypeSpecialization, int minCookingTimeMs, int maxCookingTimeMs);
    
    /// @brief destroy the Cook object
    ~Cook();

    /// @brief method that starts the cook thread
    void Run();
    void Stop() { isStopRequested = true;}

    CookState GetState() { return state; }
};
