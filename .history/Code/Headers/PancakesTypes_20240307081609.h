#pragma once

#include <string>



enum PancakeType
{
    BananaPancakes,
    BlueberryPancakes,
    ChocolatePancakes,
};

enum PancakeIngredients
{
    Banana,
    Blueberry,
    Chocolate,
    Eggs,
    Milk,
};

std::string PancakeTypeToString(PancakeType pancakeType);






