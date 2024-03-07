#pragma once

#include <map>
#include "PancakesTypes.h"

namespace Containers
{
    std::map<PancakeType, int> buffet = {
        {PancakeType::BananaPancakes, 0},
        {PancakeType::BlueberryPancakes, 0},
        {PancakeType::ChocolatePancakes, 0}
    };

    std::map<PancakeIngredient, int> fridge = {
        {PancakeIngredient::Banana, 10},
        {PancakeIngredient::Blueberry, 10},
        {PancakeIngredient::Chocolate, 10},
        {PancakeIngredient::Eggs, 30},
        {PancakeIngredient::Milk, 30}
    };


} // namespace Containers
