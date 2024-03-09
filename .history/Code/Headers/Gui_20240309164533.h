#pragma once

#include <thread>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdlib.h> 
#include <algorithm>

#include "EntityController.h"
#include "RestaurantContainers.h"

namespace Gui
{
    const std::string BREAK_LINE = "-------------------------------------------------------\n";

    extern std::string UserInput;

    const std::string CommandAddCookBanana;
    const std::string CommandAddCookChocolate;
    const std::string CommandAddCookBlueberry;
    const std::string CommandAddClient;
    const std::string CommandDeleteClient;
    const std::string CommandDeleteCookBanana;
    const std::string CommandDeleteCookChocolate;
    const std::string CommandDeleteCookBlueberry;
    const std::string CommandExit;


    void PrintRestaurant(EntityController& entityController);
    void ClearScreen();
    void PrintUserInput();

    void RunGuiOutput(EntityController& entityController, int refreshRateInMs);
    void RunGuiInput(EntityController& entityController);
} // namespace Gui


