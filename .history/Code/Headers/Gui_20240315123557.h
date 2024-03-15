#pragma once

#include <thread>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdlib.h> 
#include <algorithm>
#include <string>

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
    const std::string COMMAND_SET_FRIDGE_LIMIT_BANANA = "setfridgelimitbanana";
    const std::string COMMAND_SET_FRIDGE_LIMIT_CHOCOLATE = "setfridgelimitchocolate";
    const std::string COMMAND_SET_FRIDGE_LIMIT_BLUEBERRY = "setfridgelimitblueberry";
    const std::string COMMAND_SET_FRIDGE_LIMIT_COMMONS = "setbuffetlimitcommons";
    const std::string COMMAND_SET_BUFFET_LIMIT_BANANA = "setbuffetlimitbanana";
    const std::string COMMAND_SET_BUFFET_LIMIT_CHOCOLATE = "setbuffetlimitchocolate";
    const std::string COMMAND_SET_BUFFET_LIMIT_BLUEBERRY = "setbuffetlimitblueberry";
    const std::string COMMAND_SET_INGREDIENTS_ADD_AMOUNT = "setingredientsaddamount";


    const std::string COMMAND_EXIT = "exit";
    // COMMANDS

    /// @brief Function that prints the restaurant state (in the console)
    /// @param entityController entity controller object
    void PrintRestaurant(EntityController& entityController);

    /// @brief Function will clear the screen
    void ClearScreen();

    /// @brief Function that prints the user input and commands list
    void PrintUserInput();

    /// @brief Function runs new thread which constantly prints the restaurant state
    /// @param entityController entity controller object
    /// @param refreshRateInMs time in milliseconds that the thread will wait before printing the restaurant state again
    void RunGuiOutput(EntityController& entityController, int refreshRateInMs);

    /// @brief Function reads the user input. Runs on current thread
    /// @param entityController entity controller object
    void RunGuiInput(EntityController& entityController);
} // namespace Gui


