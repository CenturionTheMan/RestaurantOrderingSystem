#pragma once

#include <map>
#include <mutex>
#include "PancakesTypes.h"
#include "Manager.h"

namespace Containers
{
    extern std::mutex buffetMutex;
    extern std::mutex fridgeMutex;

    extern std::map<PancakeType, int> buffet;
    extern std::map<PancakeIngredient, int> fridge;

    extern std::map<PancakeType, int> buffetPancakesLimits;

    bool CheckIfEnoughIngredients(PancakeType type);
    void TakeIngredientsFromFridge(PancakeType type);
    void AddIngredientsToFridge(PancakeIngredient type, int amount);
    int GetBuffetPancakesLimit(PancakeType pancakeType);


    void AddPancakeToBuffet(PancakeType type);
    bool CheckIfCanAddToBuffet(PancakeType type);
} // namespace Containers
