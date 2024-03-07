#include "../Headers/Manager.h"


Manager::Manager(int bananaPancakesLimit, int blueberryPancakesLimit, int chocolatePancakesLimit)
{
    Manager::PancakesLimits = {
        {PancakeType::BananaPancakes, bananaPancakesLimit},
        {PancakeType::BlueberryPancakes, blueberryPancakesLimit},
        {PancakeType::ChocolatePancakes, chocolatePancakesLimit}
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