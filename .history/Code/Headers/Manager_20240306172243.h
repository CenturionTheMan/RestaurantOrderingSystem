#pragma once

#include <vector>
#include <map>
#include <mutex>
#include "Cook.h"

namespace Manager
{
    const std::map<PancakeType, int> PancakesLimits = {
        {PancakeType::BananaPancakes, 10},
        {PancakeType::BlueberryPancakes, 20},
        {PancakeType::ChocolatePancakes, 30}
    };

    std::condition_variable bananaPancakesLimitCondition;
    // std::condition_variable blueberryPancakesLimitCondition;
    // std::condition_variable chocolatePancakesLimitCondition;

    void CreateAndRunCook(std::vector<PancakeType>& buffet, std::mutex& mutex, std::condition_variable& conditionVariable, PancakeType cookSpecialization);

};


