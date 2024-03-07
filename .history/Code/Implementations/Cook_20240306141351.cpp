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
}

void Cook::CookLoop(std::vector<PancakeType>& buffet, std::mutex& mutex, std::condition_variable& conditionVariable)
{
    while (true)
    {
        std::cout << "Cooking pancake: " << PancakeTypeToString(Cook::specializedInPancakeType) << std::endl;
        int timeToCook = randomGenerator.GetRandomNumber(minCookingTimeMs, maxCookingTimeMs);
        std::this_thread::sleep_for(std::chrono::milliseconds(timeToCook));

        std::cout << "Waiting to serve: " << PancakeTypeToString(Cook::specializedInPancakeType) << std::endl;
        std::unique_lock<std::mutex> uLock(mutex);
        conditionVariable.wait(uLock, [&buffet] { 
            return buffet.size() < 100; //! condition here
         });
        buffet.push_back(Cook::specializedInPancakeType);
        uLock.unlock();

        std::cout << "Served: " << PancakeTypeToString(Cook::specializedInPancakeType) << std::endl;
    }
}


std::thread Cook::Run(std::vector<PancakeType>& buffet, std::mutex& mutex, std::condition_variable& conditionVariable)
{
    std::thread cookThread(&Cook::CookLoop, this, std::ref(buffet), std::ref(mutex), std::ref(conditionVariable));
    
    if(cookThread.joinable())
        cookThread.detach();
    
    return cookThread;
}