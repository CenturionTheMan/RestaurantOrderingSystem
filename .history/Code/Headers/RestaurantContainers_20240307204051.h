#pragma once

#include <map>
#include <mutex>
#include "PancakesTypes.h"

namespace Containers
{
    extern std::mutex buffetMutex;
    extern std::mutex fridgeMutex;

    extern std::map<PancakeType, int> buffet;
    extern std::map<PancakeIngredient, int> fridge;


    bool CheckIfEnoughIngredients(PancakeType type);
    void TakeIngredientsFromFridge(PancakeType type);

    void AddPancakeToBuffet(PancakeType type);
    bool CheckIfCanAddToBuffet(PancakeType type);
} // namespace Containers
