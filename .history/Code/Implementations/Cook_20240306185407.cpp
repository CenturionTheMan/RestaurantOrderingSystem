#include "../Headers/Cook.h"


Cook::Cook(PancakeType pancakeTypeSpecialization, int minCookingTimeMs, int maxCookingTimeMs)
{
    Cook::randomGenerator = RandomGenerator();

    Cook::specializedInPancakeType = pancakeTypeSpecialization;
    Cook::maxCookingTimeMs = maxCookingTimeMs;
    Cook::minCookingTimeMs = minCookingTimeMs;
}

Cook::~Cook()
{
    Cook::shouldAbort = true;
}


void Cook::Run(std::vector<PancakeType>& buffet, std::mutex& mutex, std::condition_variable& conditionVariable)
{
    std::thread cookThread([this, &buffet, &mutex, &conditionVariable] {

        while (Cook::shouldAbort == false)
        {
            std::cout << PancakeTypeToString(Cook::specializedInPancakeType) << ": COOKING" << std::endl;
            int timeToCook = Cook::randomGenerator.GetRandomNumber(minCookingTimeMs, maxCookingTimeMs);
            std::this_thread::sleep_for(std::chrono::milliseconds(timeToCook));

            std::cout << PancakeTypeToString(Cook::specializedInPancakeType) << "WAITING" << std::endl;
            std::unique_lock<std::mutex> uLock(mutex);

            conditionVariable.wait(uLock, [&buffet] { 
                return buffet.size() < Manager::GetPancakesLimit(PancakeType::BananaPancakes);
            });
            

            buffet.push_back(Cook::specializedInPancakeType);
            uLock.unlock();


            std::cout << PancakeTypeToString(Cook::specializedInPancakeType) << "SERVED" << std::endl;
        }

        std::cout << "Cook thread finished" << std::endl;
    });
    
    if(cookThread.joinable())
        cookThread.detach();
}