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


    switch (cookSpecialization)
    {
    case PancakeType::BananaPancakes:
        Manager::BananaPancakesCooks.push_back(newCook);
        break;
    case PancakeType::ChocolatePancakes:
        Manager::ChocolatePancakesCooks.push_back(newCook);
        break;
    case PancakeType::BlueberryPancakes:
        Manager::BlueberryPancakesCooks.push_back(newCook);
        break;
    default:
        break;
    }

    return newCook;
}