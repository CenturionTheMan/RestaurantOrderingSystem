#include "../Headers/RestaurantContainers.h"


std::map<PancakeType, int> Containers::buffet = {
    {PancakeType::BananaPancakes, 0},
    {PancakeType::BlueberryPancakes, 0},
    {PancakeType::ChocolatePancakes, 0}
};

std::map<PancakeIngredient, int> Containers::fridge = {
    {PancakeIngredient::Banana, 0},
    {PancakeIngredient::Blueberry, 0},
    {PancakeIngredient::Chocolate, 0},
    {PancakeIngredient::Eggs, 0},
    {PancakeIngredient::Milk, 0}
};