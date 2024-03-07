#pragma once

#include <vector>
#include <map>
#include "Cook.h"

namespace Manager
{
    std::map<PancakeType, int> PancakesLimits; 
    const Pancakes RestaurantPancakes[] = {
    {PancakeType::BananaPancakes, 20},
    {PancakeType::BlueberryPancakes, 30},
    {PancakeType::ChocolatePancakes, 40}};


    std::vector<std::thread> BananaPancakesCookThreads;
    std::vector<std::thread> BlueberryPancakesCookThreads;
    std::vector<std::thread> ChocolatePancakesCookThreads;

    void CreateAndRunCook(std::vector<PancakeType>& buffet, std::mutex& mutex, std::condition_variable& conditionVariable, PancakeType cookSpecialization)
    {
        Cook newCook(cookSpecialization, 1000, 3000);
        std::thread cookThread = newCook.Run(buffet, mutex, conditionVariable);

        switch (cookSpecialization)
        {
        case PancakeType::BananaPancakes:
            Manager::BananaPancakesCookThreads.push_back(cookThread);
            break;
        case PancakeType::ChocolatePancakes:
            Manager::ChocolatePancakesCookThreads.push_back(cookThread);
            break;
        case PancakeType::BlueberryPancakes:
            Manager::BlueberryPancakesCookThreads.push_back(cookThread);
            break;
        default:
            break;
        }
    }
};


