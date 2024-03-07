#pragma once

#include <vector>
#include "Cook.h"

class Manager
{
private:
    std::vector<std::thread> BananaPancakesCookThreads;
    std::vector<std::thread> BlueberryPancakesCookThreads;
    std::vector<std::thread> ChocolatePancakesCookThreads;

    int desiredBananaPancakes, desiredBlueberryPancakes, desiredChocolatePancakes;

public:
    Manager(int desiredBananaPancakes, int desiredBlueberryPancakes, int desiredChocolatePancakes);
    ~Manager();

    Cook CreateAndRunCook(std::vector<PancakeType>& buffet, std::mutex& mutex, std::condition_variable& conditionVariable, PancakeType cookSpecialization);
};

Manager::Manager(int desiredBananaPancakes, int desiredBlueberryPancakes, int desiredChocolatePancakes)
{
    Manager::desiredBananaPancakes = desiredBananaPancakes;
    Manager::desiredBlueberryPancakes = desiredBlueberryPancakes;
    Manager::desiredChocolatePancakes = desiredChocolatePancakes;

}

Manager::~Manager()
{
}

Cook Manager::CreateAndRunCook(std::vector<PancakeType>& buffet, std::mutex& mutex, std::condition_variable& conditionVariable, PancakeType cookSpecialization)
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

    return newCook;
}