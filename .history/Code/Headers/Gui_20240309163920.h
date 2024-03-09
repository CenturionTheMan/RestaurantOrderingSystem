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

    extern std::string CommandAddCookBanana;
    extern std::string CommandAddCookChocolate;
    extern std::string CommandAddCookBlueberry;
    extern std::string CommandAddClient;
    extern std::string CommandDeleteClient;
    extern std::string CommandDeleteCookBanana;
    extern std::string CommandDeleteCookChocolate;
    extern std::string CommandDeleteCookBlueberry;
    extern std::string CommandExit;


    void PrintRestaurant(EntityController& entityController);
    void ClearScreen();
    void PrintUserInput();

    void RunGuiOutput(EntityController& entityController, int refreshRateInMs);
    void RunGuiInput(EntityController& entityController);
} // namespace Gui


