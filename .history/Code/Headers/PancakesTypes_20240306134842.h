#pragma once
#include <string>

enum PancakeType
{
    BananaPancakes,
    BlueberryPancakes,
    ChocolateChipPancakes,
    PlainPancakes,
};

std::string PancakeTypeToString(PancakeType pancakeType)
{
    switch (pancakeType)
    {
        case PancakeType::BananaPancakes:
            return "Banana Pancakes";
        case PancakeType::BlueberryPancakes:
            return "Blueberry Pancakes";
        case PancakeType::ChocolateChipPancakes:
            return "Chocolate Chip Pancakes";
        case PancakeType::PlainPancakes:
            return "Plain Pancakes";
        default:
            return "Unknown Pancake Type";
    }
}





