#include "Enums/PancakesTypes.cpp"
#include "RandomGenerator.h"
#include <vector>
#include <thread>
#include <mutex>

class Cook
{
private:
    RandomGenerator randomGenerator;

    PancakeType specializedInPancakeType;
    int maxCookingTimeMs;
    int minCookingTimeMs;

    void CookLoop(std::vector<PancakeType>& buffet);
    
public:
    Cook(PancakeType pancakeTypeSpecialization, int maxCookingTimeMs, int minCookingTimeMs);
    ~Cook();

    void Run(std::vector<PancakeType>& buffet);
};

void Cook::CookLoop(std::vector<PancakeType>& buffet)
{
    while (true)
    {
        int timeToCook = randomGenerator.GetRandomNumber(minCookingTimeMs, maxCookingTimeMs);
        std::this_thread::sleep_for(std::chrono::milliseconds(timeToCook));


        buffet.push_back(Cook::specializedInPancakeType);
    }
}


void Cook::Run(std::vector<PancakeType>& buffet)
{
    // std::thread t(&Cook::CookLoop, this, std::ref(buffet)); //? Why "this"? 
    std::thread t(&Cook::CookLoop, std::ref(buffet));
}


