#include "../Headers/Manager.h"


//! Will not compile without it, why? - no idea
std::map<PancakeType, int> Manager::pancakesLimits;
std::condition_variable Manager::bananaPancakesLimitCondition;
std::condition_variable Manager::blueberryPancakesLimitCondition;
std::condition_variable Manager::chocolatePancakesLimitCondition;


Manager::Manager(int bananaPancakesLimit, int blueberryPancakesLimit, int chocolatePancakesLimit)
{
    Manager::pancakesLimits.insert({PancakeType::BananaPancakes, bananaPancakesLimit});
    Manager::pancakesLimits.insert({PancakeType::BlueberryPancakes, blueberryPancakesLimit});
    Manager::pancakesLimits.insert({PancakeType::ChocolatePancakes, chocolatePancakesLimit});
}

Manager::~Manager()
{
    for (int i = 0; i < Manager::bananaCooks.size(); i++)
    {
        delete Manager::bananaCooks[i];
    }

    for (int i = 0; i < Manager::chocolateCooks.size(); i++)
    {
        delete Manager::chocolateCooks[i];
    }

    for (int i = 0; i < Manager::blueberryCooks.size(); i++)
    {
        delete Manager::blueberryCooks[i];
    }
    

}


void Manager::CreateAndRunCook(std::vector<PancakeType>& buffet, std::mutex& mutex, std::condition_variable& conditionVariable, PancakeType cookSpecialization)
{
    Cook* newCook = new Cook(cookSpecialization, 1000, 3000);
    newCook->Run(buffet, mutex, conditionVariable);

    switch (cookSpecialization)
    {
        case PancakeType::BananaPancakes:
            bananaCooks.push_back(newCook);
            break;
        case PancakeType::BlueberryPancakes:
            blueberryCooks.push_back(newCook);
            break;
        case PancakeType::ChocolatePancakes:
            chocolateCooks.push_back(newCook);
            break;
    }

}

int Manager::GetPancakesLimit(PancakeType pancakeType)
{
    return Manager::pancakesLimits[pancakeType];
}