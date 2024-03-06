#include "Headers/Cook.h"


Cook::Cook(std::vector<PancakeType>& buffet, PancakeType pancakeTypeSpecialization)
{
    Cook::specializedInPancakeType = pancakeTypeSpecialization;
}

Cook::~Cook()
{
}