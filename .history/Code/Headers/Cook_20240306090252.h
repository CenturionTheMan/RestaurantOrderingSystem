#include "RandomGenerator.h"
#include "Code/Enums/PancakesTypes.cpp"

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

    void CookLoop(std::vector<PancakeType>& buffet, std::mutex& mutex);
    
public:
    Cook(PancakeType pancakeTypeSpecialization, int minCookingTimeMs, int maxCookingTimeMs);
    ~Cook();

    void Run(std::vector<PancakeType>& buffet, std::mutex& mutex);
};




