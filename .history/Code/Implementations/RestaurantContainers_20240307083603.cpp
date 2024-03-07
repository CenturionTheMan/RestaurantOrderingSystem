#include "../Headers/RestaurantContainers.h"


// std::map<PancakeType, int> Containers::buffet;

// std::map<PancakeIngredient, int> Containers::fridge;
std::map<PancakeType, int> Containers::buffet = {
    {PancakeType::BananaPancakes, 0},
    {PancakeType::BlueberryPancakes, 0},
    {PancakeType::ChocolatePancakes, 0}
};

std::map<PancakeIngredient, int> Containers::fridge = {
    {PancakeIngredient::Banana, 10},
    {PancakeIngredient::Blueberry, 10},
    {PancakeIngredient::Chocolate, 10},
    {PancakeIngredient::Eggs, 30},
    {PancakeIngredient::Milk, 30}
};