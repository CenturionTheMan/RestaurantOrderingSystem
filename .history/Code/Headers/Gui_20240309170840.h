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

    /// @brief Function that prints the restaurant state (in the console)
    /// @param entityController entity controller object
    void PrintRestaurant(EntityController& entityController);

    /// @brief Function will clear the screen
    void ClearScreen();

    /// @brief Function that prints the user input and commands list
    void PrintUserInput();

    /// @brief Function prints simulation state and runs it in new thread
    /// @param entityController 
    /// @param refreshRateInMs 
    void RunGuiOutput(EntityController& entityController, int refreshRateInMs);
    void RunGuiInput(EntityController& entityController);
} // namespace Gui


