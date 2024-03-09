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
    /// @param type pancake type
    void TakeIngredientsFromFridge(PancakeType type);

    /// @brief Function that adds ingredients to the fridge
    /// @param type Pancake ingredient type to add
    /// @param amount amount of ingredients to add
    void AddIngredientsToFridge(PancakeIngredient type, int amount);


    /// @brief Function will return the maximum amount of pancakes that can be in the buffet 
    /// @param type Pancake type
    int GetBuffetPancakesLimit(PancakeType pancakeType);

    /// @brief Function will add 1 pancake of given type to the buffet
    void AddPancakeToBuffet(PancakeType type);

    /// @brief Function will check if there is space in the buffet for a pancake of given type
    /// @param type pancake type
    /// @return true if there is space, false otherwise
    bool CheckIfCanAddToBuffet(PancakeType type);

    /// @brief Function will take a pancake of given type from the buffet
    /// @param type pancake type
    /// @return true if the pancake was taken, false otherwise 
    bool TakePancakeFromBuffet(PancakeType type);
    
} // namespace Containers
