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
    

    void CookPancake();
    void ServePancake();
public:
    Cook(std::vector<PancakeType>& buffet, PancakeType pancakeTypeSpecialization, int maxCookingTimeMs, int minCookingTimeMs);
    ~Cook();

    void Run();
};

void Cook::CookPancake()
{
    int timeToCook = randomGenerator.GetRandomNumber(minCookingTimeMs, maxCookingTimeMs);
    std::this_thread::sleep_for(std::chrono::milliseconds(timeToCook));
}

void Cook::ServePancake()
{
    
}

void Cook::Run()
{
    while (true)
    {
        Cook::CookPancake();
        Cook::ServePancake();
    }
}


