#include "Enums/PancakesTypes.cpp"
#include "RandomGenerator.h"
#include <vector>
#include <thread>

class Cook
{
private:
    RandomGenerator randomGenerator;

    PancakeType specializedInPancakeType;
    int maxCookingTimeMs;
    int minCookingTimeMs;

    void CookLoop();
    
public:
    Cook(PancakeType pancakeTypeSpecialization, int maxCookingTimeMs, int minCookingTimeMs);
    ~Cook();

    void Run();
};

void Cook::CookLoop(std::vector<PancakeType>& buffet)
{
    while (true)
    {
        int timeToCook = randomGenerator.GetRandomNumber(minCookingTimeMs, maxCookingTimeMs);
        std::this_thread::sleep_for(std::chrono::milliseconds(timeToCook));

        Cook::buffet.push_back(Cook::specializedInPancakeType);
    }
}


void Cook::Run()
{
    std::thread t(&Cook::CookLoop);
}


