#include "../Headers/Manager.h"


//! Will not compile without it, why? - no idea
std::map<PancakeType, int> Manager::pancakesLimits;
std::condition_variable Manager::bananaPancakesLimitCondition;
std::condition_variable Manager::blueberryPancakesLimitCondition;
std::condition_variable Manager::chocolatePancakesLimitCondition;
std::condition_variable Manager::fridgeConditionVariable;


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


void Manager::CreateAndRunCook(PancakeType cookSpecialization)
{
    Cook* newCook = new Cook(cookSpecialization, 1000, 3000);

    switch (cookSpecialization)
    {
        case PancakeType::BananaPancakes:
            newCook->Run(Manager::bananaPancakesLimitCondition);
            bananaCooks.push_back(newCook);
            break;
        case PancakeType::BlueberryPancakes:
            newCook->Run(Manager::blueberryPancakesLimitCondition);
            blueberryCooks.push_back(newCook);
            break;
        case PancakeType::ChocolatePancakes:
            newCook->Run(Manager::chocolatePancakesLimitCondition);
            chocolateCooks.push_back(newCook);
            break;
    }

}

void Manager::RunManager()
{
    std::thread managerThread([this] {
        while (true)
        {
            std::unique_lock<std::mutex> fridgeLock(Containers::fridgeMutex);
            

            
            fridgeConditionVariable.notify_all();
            fridgeLock.unlock();
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    });

    if(managerThread.joinable())
        managerThread.detach();

}


int Manager::GetPancakesLimit(PancakeType pancakeType)
{
    return Manager::pancakesLimits[pancakeType];
}