#pragma once

#include <string>



enum PancakeType
{
    BananaPancakes,
    BlueberryPancakes,
    ChocolatePancakes,
};

enum PancakeIngredient
{
    Banana,
    Blueberry,
    Chocolate,
    Eggs,
    Milk,
    Flour
};

std::string PancakeTypeToString(PancakeType pancakeType);






