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
     
    std::string CommandAddCookBanana = "addcookbanana";
    std::string CommandAddCookChocolate = "addcookchocolate";
    std::string CommandAddCookBlueberry = "addcookblueberry";
    std::string CommandAddClient = "addclient";
    std::string CommandDeleteClient = "deleteclient";
    std::string CommandDeleteCookBanana = "deletecookbanana";
    std::string CommandDeleteCookChocolate = "deletecookchocolate";
    std::string CommandDeleteCookBlueberry = "deletecookblueberry";
    std::string CommandExit = "exit";

    void PrintRestaurant(EntityController& entityController);
    void ClearScreen();
    void PrintUserInput();

    void RunGuiOutput(EntityController& entityController, int refreshRateInMs);
    void RunGuiInput(EntityController& entityController);
} // namespace Gui


