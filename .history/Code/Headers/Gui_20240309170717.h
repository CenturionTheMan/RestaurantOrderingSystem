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
    /// @brief user input
    extern std::string UserInput;


    const std::string BREAK_LINE = "-------------------------------------------------------\n";

    // COMMANDS
    const std::string COMMAND_ADD_COOK_BANANA = "addcookbanana";
    const std::string COMMAND_ADD_COOK_CHOCOLATE = "addcookchocolate";
    const std::string COMMAND_ADD_COOK_BLUEBERRY = "addcookblueberry";
    const std::string COMMAND_ADD_CLIENT = "addclient";
    const std::string COMMAND_DELETE_CLIENT = "deleteclient";
    const std::string COMMAND_DELETE_COOK_BANANA = "deletecookbanana";
    const std::string COMMAND_DELETE_COOK_CHOCOLATE = "deletecookchocolate";
    const std::string COMMAND_DELETE_COOK_BLUEBERRY = "deletecookblueberry";
    const std::string COMMAND_EXIT = "exit";
    // COMMANDS

    void PrintRestaurant(EntityController& entityController);
    void ClearScreen();
    void PrintUserInput();

    void RunGuiOutput(EntityController& entityController, int refreshRateInMs);
    void RunGuiInput(EntityController& entityController);
} // namespace Gui


