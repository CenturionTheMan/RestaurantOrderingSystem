#include "../Headers/Manager.h"


//! Will not compile without it, why? - no idea
std::map<PancakeType, int> Manager::pancakesLimits;


Manager::Manager(int bananaPancakesLimit, int blueberryPancakesLimit, int chocolatePancakesLimit)
{
    Manager::pancakesLimits.insert({PancakeType::BananaPancakes, bananaPancakesLimit});
    Manager::pancakesLimits.insert({PancakeType::BlueberryPancakes, blueberryPancakesLimit});
    Manager::pancakesLimits.insert({PancakeType::ChocolatePancakes, chocolatePancakesLimit});
}

Manager::~Manager()
{
}


void Manager::CreateAndRunCook(std::vector<PancakeType>& buffet, std::mutex& mutex, std::condition_variable& conditionVariable, PancakeType cookSpecialization)
{
    // std::unique_ptr<Cook> newCook = std::make_unique<Cook>(cookSpecialization, 1000, 3000);
    // newCook->Run(buffet, mutex, conditionVariable);

    Cook* cook = new Cook(cookSpecialization, 1000, 3000);
    cook->Run(buffet, mutex, conditionVariable);
}

std::condition_variable& GetPancakesLimitCondition(PancakeType pancakeType)
{
    switch (pancakeType)
    {
    case PancakeType::BananaPancakes:
        return Manager::bananaPancakesLimitCondition;
        break;
    case PancakeType::BlueberryPancakes:
        return Manager::blueberryPancakesLimitCondition;
        break;
    case PancakeType::ChocolatePancakes:
        return Manager::chocolatePancakesLimitCondition;
        break;
    default:
        break;
    }
}



int Manager::GetPancakesLimit(PancakeType pancakeType)
{
    return Manager::pancakesLimits[pancakeType];
}