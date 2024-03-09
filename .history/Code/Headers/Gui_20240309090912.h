#pragma once

#include <thread>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdlib.h> 

#include "EntityController.h"
#include "RestaurantContainers.h"

namespace Gui
{
    const std::string BREAK_LINE = "-------------------------------------------------------\n";

    extern std::string UserInput;

    void PrintRestaurant(EntityController& entityController);
    void ClearScreen();
    std::string HandleUserInput(EntityController& entityController);

    void RunGui(EntityController& entityController, int refreshRateInMs);

} // namespace Gui


