#include "../Headers/PancakesTypes.h"

std::string PancakeTypeToString(PancakeType pancakeType)
{
    switch (pancakeType)
    {
        case PancakeType::BananaPancakes:
            return "Banana Pancakes    |";
        case PancakeType::BlueberryPancakes:
            return "Blueberry Pancakes |";
        case PancakeType::ChocolatePancakes:
            return "Chocolate Pancakes |";
        default:
            return "Unknown Pancake Type";
    }
}