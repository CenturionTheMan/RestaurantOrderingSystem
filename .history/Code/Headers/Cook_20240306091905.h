#pragma once


#include "RandomGenerator.h"
#include <vector>
#include <thread>
#include <mutex>
#include "PancakesTypes.h"

class Cook
{
private:
    RandomGenerator randomGenerator;

    PancakeType specializedInPancakeType;
    int maxCookingTimeMs;
    int minCookingTimeMs;

    void CookLoop(std::vector<PancakeType>& buffet, std::mutex& mutex);
    
public:
    Cook(PancakeType pancakeTypeSpecialization, int minCookingTimeMs, int maxCookingTimeMs);
    ~Cook();

    void Run(std::vector<PancakeType>& buffet, std::mutex& mutex);
};




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

void Cook::CookLoop(std::vector<PancakeType>& buffet, std::mutex& mutex)
{
    while (true)
    {
        std::cout << "Cooking pancake: " << Cook::specializedInPancakeType << std::endl;
        int timeToCook = randomGenerator.GetRandomNumber(minCookingTimeMs, maxCookingTimeMs);
        std::this_thread::sleep_for(std::chrono::milliseconds(timeToCook));

        std::cout << "Waiting to serve: " << Cook::specializedInPancakeType << std::endl;
        mutex.lock();
        buffet.push_back(Cook::specializedInPancakeType);
        mutex.unlock();

        std::cout << "Served: " << Cook::specializedInPancakeType << std::endl;
    }
}


void Cook::Run(std::vector<PancakeType>& buffet, std::mutex& mutex)
{
    // std::thread t(&Cook::CookLoop, this, std::ref(buffet)); //? Why "this"? 
    // std::thread t(&Cook::CookLoop, std::ref(buffet));
}