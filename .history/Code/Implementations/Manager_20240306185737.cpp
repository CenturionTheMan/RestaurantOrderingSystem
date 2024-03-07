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
    while (!Manager::bananaCooks.empty())
    {
        Cook* cook = Manager::bananaCooks.back();
        Manager::bananaCooks.pop_back();
        delete cook;
    }

    while (!Manager::blueberryCooks.empty())
    {
        Cook* cook = Manager::blueberryCooks.back();
        Manager::blueberryCooks.pop_back();
        delete cook;
    }

    while (!Manager::chocolateCooks.empty())
    {
        Cook* cook = Manager::chocolateCooks.back();
        Manager::chocolateCooks.pop_back();
        delete cook;
    }
}


void Manager::CreateAndRunCook(std::vector<PancakeType>& buffet, std::mutex& mutex, PancakeType cookSpecialization)
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