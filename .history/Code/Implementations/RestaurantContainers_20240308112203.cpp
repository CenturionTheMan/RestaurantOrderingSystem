#include "../Headers/RestaurantContainers.h"


std::mutex Containers::buffetMutex;
std::mutex Containers::fridgeMutex;


std::map<PancakeType, int> Containers::buffet = {
    {PancakeType::BananaPancakes, 0},
    {PancakeType::BlueberryPancakes, 0},
    {PancakeType::ChocolatePancakes, 0}
};

std::map<PancakeIngredient, int> Containers::fridge = {
    {PancakeIngredient::Banana, 0},
    {PancakeIngredient::Blueberry, 0},
    {PancakeIngredient::Chocolate, 0},
    {PancakeIngredient::Eggs_Milk_Flour, 0},
};
 
std::map<PancakeType, int> Containers::buffetPancakesLimits = {
    {PancakeType::BananaPancakes, 10},
    {PancakeType::BlueberryPancakes, 20},
    {PancakeType::ChocolatePancakes, 30}
 };

std::map<PancakeIngredient, int> Containers::fridgeIngredientLimits = {
    {PancakeIngredient::Banana, 30},
    {PancakeIngredient::Blueberry, 30},
    {PancakeIngredient::Chocolate, 30},
    {PancakeIngredient::Eggs_Milk_Flour, 50},
};



bool Containers::CheckIfEnoughIngredients(PancakeType type)
{
    switch (type)
    {
        case PancakeType::BananaPancakes:
            return Containers::fridge[PancakeIngredient::Banana] > 0 && Containers::fridge[PancakeIngredient::Eggs_Milk_Flour];
        case PancakeType::BlueberryPancakes:
            return Containers::fridge[PancakeIngredient::Blueberry] > 0 && Containers::fridge[PancakeIngredient::Eggs_Milk_Flour];
        case PancakeType::ChocolatePancakes:
            return Containers::fridge[PancakeIngredient::Chocolate] > 0 && Containers::fridge[PancakeIngredient::Eggs_Milk_Flour];
        default:
            return false;
    }
}

void Containers::TakeIngredientsFromFridge(PancakeType type)
{
    switch (type)
    {
        case PancakeType::BananaPancakes:
            Containers::fridge[PancakeIngredient::Banana]--;
            break;
        case PancakeType::BlueberryPancakes:
            Containers::fridge[PancakeIngredient::Blueberry]--;
            break;
        case PancakeType::ChocolatePancakes:
            Containers::fridge[PancakeIngredient::Chocolate]--;
            break;
        default:
            break;
    }
    Containers::fridge[PancakeIngredient::Eggs_Milk_Flour]--;
}

int Containers::GetBuffetPancakesLimit(PancakeType pancakeType)
{
    return Containers::buffetPancakesLimits[pancakeType];
}

void Containers::AddIngredientsToFridge(PancakeIngredient type, int amount)
{
    Containers::fridge[type] += amount;
}


void Containers::AddPancakeToBuffet(PancakeType type)
{
    Containers::buffet[type]++;
}

bool Containers::CheckIfCanAddToBuffet(PancakeType type)
{
    return Containers::buffet[type] <= Containers::GetBuffetPancakesLimit(type);
}

void Containers::TakePancakeFromBuffet(PancakeType type)
{
    Containers::buffet[type]--;
}
