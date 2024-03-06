#include "Headers/Cook.h"


Cook::Cook(std::vector<PancakeType>& buffet, PancakeType pancakeTypeSpecialization, int maxCookingTimeMs, int minCookingTimeMs)
{
    Cook::randomGenerator = RandomGenerator();

    Cook::specializedInPancakeType = pancakeTypeSpecialization;
    Cook::maxCookingTimeMs = maxCookingTimeMs;
    Cook::minCookingTimeMs = minCookingTimeMs;
}

Cook::~Cook()
{
}