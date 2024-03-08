#pragma once

#include <map>
#include <mutex>
#include "PancakesTypes.h"
#include "Manager.h"

namespace Containers
{
    /// @brief mutex that will be used to lock the buffet
    extern std::mutex buffetMutex;

    /// @brief mutex that will be used to lock the fridge
    extern std::mutex fridgeMutex;

    /// @brief map that represents the buffet
    extern std::map<PancakeType, int> buffet;

    /// @brief map that represents the fridge
    extern std::map<PancakeIngredient, int> fridge;

    /// @brief map that represents the limits of the buffet
    extern std::map<PancakeType, int> buffetPancakesLimits;

    /// @brief map that represents the limits of the fridge
    extern std::map<PancakeIngredient, int> fridgeIngredientLimits;

    /// @brief Function that checks if there are enough ingredients in the fridge to make a pancake (more than 0)
    /// @param type pancake type
    /// @return true if there are enough ingredients, false otherwise
    bool CheckIfEnoughIngredients(PancakeType type);

    /// @brief Function that takes the ingredients from the fridge (one from each needed ingredient)
    /// @param type 
    void TakeIngredientsFromFridge(PancakeType type);
    void AddIngredientsToFridge(PancakeIngredient type, int amount);
    int GetBuffetPancakesLimit(PancakeType pancakeType);


    void AddPancakeToBuffet(PancakeType type);
    bool CheckIfCanAddToBuffet(PancakeType type);
    void TakePancakeFromBuffet(PancakeType type);
} // namespace Containers
