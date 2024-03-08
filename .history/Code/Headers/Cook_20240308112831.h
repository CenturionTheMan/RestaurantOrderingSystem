#pragma once

#include <thread>
#include <mutex>
#include <condition_variable>

#include "RandomGenerator.h"
#include "PancakesTypes.h"
#include "Manager.h"
#include "RestaurantContainers.h"

/// @brief Class that represents a cook that prepares pancakes
class Cook
{
private:

    /// @brief random generator used to generate random cooking time
    RandomGenerator randomGenerator;

    /// @brief type of pancake that the cook specializes in (makes)
    PancakeType specializedInPancakeType;

    /// @brief pointer to the condition variable that the cook will wait on (fridge and buffet)
    std::condition_variable* conditionVariable;

    /// @brief minimum and maximum cooking time in milliseconds
    int maxCookingTimeMs, minCookingTimeMs;


public:
    Cook(Manager& manager, PancakeType pancakeTypeSpecialization, int minCookingTimeMs, int maxCookingTimeMs);
    ~Cook();

    void Run();
};
