#include "../Headers/Manager.h"


Manager::Manager(/* args */)
{
    Manager::PancakesLimits = {
        {PancakeType::BananaPancakes, 10},
        {PancakeType::BlueberryPancakes, 20},
        {PancakeType::ChocolatePancakes, 30}
    };
}

Manager::~Manager()
{
}


void Manager::CreateAndRunCook(std::vector<PancakeType>& buffet, std::mutex& mutex, std::condition_variable& conditionVariable, PancakeType cookSpecialization)
{
    Cook newCook(cookSpecialization, 1000, 3000);
    newCook.Run(buffet, mutex, conditionVariable);
}