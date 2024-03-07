#include "../Headers/RestaurantContainers.h"


std::mutex Containers::buffetMutex;
std::mutex Containers::fridgeMutex;


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


bool Containers::CheckIfEnoughIngredients(PancakeType type)
{
    bool isBase = fridge[PancakeIngredient::Eggs] > 0 && fridge[PancakeIngredient::Milk] > 0 && fridge[PancakeIngredient::Flour] > 0;
    switch (type)
    {
        case PancakeType::BananaPancakes:
            return fridge[PancakeIngredient::Banana] > 0 && isBase;
        case PancakeType::BlueberryPancakes:
            return fridge[PancakeIngredient::Blueberry] > 0 && isBase;
        case PancakeType::ChocolatePancakes:
            return fridge[PancakeIngredient::Chocolate] > 0 && isBase;
        default:
            return false;
    }
}

void Containers::TakeIngredientsFromFridge(PancakeType type)
{
    switch (type)
    {
        case PancakeType::BananaPancakes:
            fridge[PancakeIngredient::Banana]--;
            break;
        case PancakeType::BlueberryPancakes:
            fridge[PancakeIngredient::Blueberry]--;
            break;
        case PancakeType::ChocolatePancakes:
            fridge[PancakeIngredient::Chocolate]--;
            break;
        default:
            break;
    }
    fridge[PancakeIngredient::Eggs]--;
    fridge[PancakeIngredient::Milk]--;
    fridge[PancakeIngredient::Flour]--;
}

void Containers::AddPancakeToBuffet(PancakeType type)
{
    Containers::buffet[type]++;
}

bool CheckIfCanAddToBuffet(PancakeType type)
{
    return Containers::buffet[type] <= Manager::GetPancakesLimit(type);
}