#pragma once

#include <ncurses.h>
#include "EntityController.h"
#include "RestaurantContainers.h"
#include <string>
#include <iomanip>
#include <sstream>
#include <algorithm>

class GuiNcurses
{
private:
    // WINDOW DIMENSIONS
    const int WINDOW_HEIGHT = 30;
    const int WINDOW_WIDTH = 130;
    const int WINDOW_START_X = 0;
    const int WINDOW_START_Y = 0;


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
    const std::string COMMAND_SET_INGREDIENTS_TO_ADD_AMOUNT = "setingredientstoaddamount";
    const std::string COMMAND_EXIT = "exit";
    
    // windows holders 
    WINDOW* contentWindow = NULL;
    WINDOW* bottomWindow = NULL;;
    WINDOW* leftWindow = NULL;;
    WINDOW* rightWindow = NULL;;

    // entity controller
    EntityController* entityController = NULL;

    // user input holder
    std::stringstream userInputStream;

    /// @brief Function which draws the content window
    void DrawContent();

    /// @brief Function which draws the left (commands) window
    void DrawLeft();

    /// @brief Function which draws the right (containers) window
    void DrawRight();

    /// @brief Function which draws the bottom (input) window
    void DrawBottom();

public:
    GuiNcurses(EntityController& entityController);
    ~GuiNcurses();

    void RunGui();
};


