#include "../Headers/Manager.h"


//! Will not compile without it, why? - no idea
std::map<PancakeType, int> Manager::PancakesLimits;


Manager::Manager(int bananaPancakesLimit, int blueberryPancakesLimit, int chocolatePancakesLimit)
{
    Manager::PancakesLimits.insert({PancakeType::BananaPancakes, bananaPancakesLimit});
    Manager::PancakesLimits.insert({PancakeType::BlueberryPancakes, blueberryPancakesLimit});
    Manager::PancakesLimits.insert({PancakeType::ChocolatePancakes, chocolatePancakesLimit});
}

Manager::~Manager()
{
}


void Manager::CreateAndRunCook(std::vector<PancakeType>& buffet, std::mutex& mutex, std::condition_variable& conditionVariable, PancakeType cookSpecialization)
{
    Cook newCook(cookSpecialization, 1000, 3000);
    newCook.Run(buffet, mutex, conditionVariable);
}

int Manager::GetPancakesLimit(PancakeType pancakeType)
{
    return Manager::PancakesLimits[pancakeType];
}