#pragma once

#include <vector>
#include <map>
#include "Cook.h"

namespace Manager
{
    const std::map<PancakeType, int> PancakesLimits = {
        {PancakeType::BananaPancakes, 10},
        {PancakeType::BlueberryPancakes, 20},
        {PancakeType::ChocolatePancakes, 30}
    };


    std::vector<std::thread> BananaPancakesCookThreads;
    std::vector<std::thread> BlueberryPancakesCookThreads;
    std::vector<std::thread> ChocolatePancakesCookThreads;

    void CreateAndRunCook(std::vector<PancakeType>& buffet, std::mutex& mutex, std::condition_variable& conditionVariable, PancakeType cookSpecialization);
    
};


