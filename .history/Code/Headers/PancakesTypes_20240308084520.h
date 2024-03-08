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
    Eggs_Milk_Flour,
};

std::string PancakeTypeToString(PancakeType pancakeType);






