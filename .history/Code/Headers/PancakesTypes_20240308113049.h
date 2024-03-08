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

/// @brief Transforms a PancakeType to a string
/// @param pancakeType 
/// @return string representation of the pancake type
std::string PancakeTypeToString(PancakeType pancakeType);






