#include "../Headers/Manager.h"

void Manager::CreateAndRunCook(std::vector<PancakeType>& buffet, std::mutex& mutex, std::condition_variable& conditionVariable, PancakeType cookSpecialization)
{
    Cook newCook(cookSpecialization, 1000, 3000);
    std::thread cookThread = newCook.Run(buffet, mutex, conditionVariable);

    
}