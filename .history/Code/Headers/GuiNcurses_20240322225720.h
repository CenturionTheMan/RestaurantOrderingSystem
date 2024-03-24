#pragma once

#include <ncurses.h>
#include "EntityController.h"
#include "RestaurantContainers.h"
#include <string>
#include <sstream>

class GuiNcurses
{
private:
    const int WINDOW_HEIGHT = 30;
    const int WINDOW_WIDTH = 130;
    const int WINDOW_START_X = 0;
    const int WINDOW_START_Y = 0;

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
    
    WINDOW* contentWindow;
    WINDOW* bottomWindow;
    WINDOW* leftWindow;
    WINDOW* rightWindow;

    EntityController* entityController;

    void DrawContent();
    void DrawLeft();
    void DrawRight();

public:
    GuiNcurses(EntityController& entityController);
    ~GuiNcurses();

    void RunGui();
    
};

void GuiNcurses::DrawRight()
{
    mvwprintw(rightWindow, 4, 2, "%s", (COMMAND_ADD_CLIENT + "^X").data());
    mvwprintw(rightWindow, 5, 2, "%s", COMMAND_DELETE_CLIENT.data());
    mvwprintw(rightWindow, 6, 2, "%s", COMMAND_ADD_COOK_BANANA.data());
    mvwprintw(rightWindow, 7, 2, "%s", COMMAND_ADD_COOK_CHOCOLATE.data());
    mvwprintw(rightWindow, 8, 2, "%s", COMMAND_ADD_COOK_BLUEBERRY.data());
    mvwprintw(rightWindow, 9, 2, "%s", COMMAND_DELETE_COOK_BANANA.data());
    mvwprintw(rightWindow, 10, 2, "%s", COMMAND_DELETE_COOK_CHOCOLATE.data());
    mvwprintw(rightWindow, 11, 2, "%s", COMMAND_DELETE_COOK_BLUEBERRY.data());
    mvwprintw(rightWindow, 12, 2, "%s", COMMAND_SET_FRIDGE_LIMIT_BANANA.data());
    mvwprintw(rightWindow, 13, 2, "%s", COMMAND_SET_FRIDGE_LIMIT_CHOCOLATE.data());
    mvwprintw(rightWindow, 14, 2, "%s", COMMAND_SET_FRIDGE_LIMIT_BLUEBERRY.data());
    mvwprintw(rightWindow, 15, 2, "%s", COMMAND_SET_FRIDGE_LIMIT_COMMONS.data());
    mvwprintw(rightWindow, 16, 2, "%s", COMMAND_SET_BUFFET_LIMIT_BANANA.data());
    mvwprintw(rightWindow, 17, 2, "%s", COMMAND_SET_BUFFET_LIMIT_CHOCOLATE.data());
    mvwprintw(rightWindow, 18, 2, "%s", COMMAND_SET_BUFFET_LIMIT_BLUEBERRY.data());
    mvwprintw(rightWindow, 19, 2, "%s", COMMAND_SET_INGREDIENTS_TO_ADD_AMOUNT.data());
    mvwprintw(rightWindow, 20, 2, "%s", COMMAND_EXIT.data());

    wrefresh(rightWindow);
}

void GuiNcurses::DrawContent()
{
    std::stringstream stream;

    //DRAW FRIDGE
    stream << "COOKS:" << std::setw(4) << std::right << GuiNcurses::entityController->GetAmountOfCooksInGivenState(CookState::WaitingForFridge);
    mvwvline(contentWindow, 3, contentWindow->_maxx - 7, (int)'#', 3);
    mvwvline(contentWindow, 3, contentWindow->_maxx - 16, (int)'#', 3);
    mvwprintw(contentWindow, 4, contentWindow->_maxx - 15, " FRIDGE ");
    mvwhline(contentWindow, 3, contentWindow->_maxx - 16, (int)'#', 9);
    mvwhline(contentWindow, 5, contentWindow->_maxx - 16, (int)'#', 9);
    mvwprintw(contentWindow, 6, contentWindow->_maxx - 16, "%s", stream.str().c_str());
    stream.str(std::string());

    //DRAW WALKING COOKS TO FRIDGE
    stream << "COOKS:" << std::setw(4) << std::right << GuiNcurses::entityController->GetAmountOfCooksInGivenState(CookState::GoingToFridge);
    mvwvline(contentWindow, 11, contentWindow->_maxx - 5, (int)'#', 3);
    mvwvline(contentWindow, 11, contentWindow->_maxx - 16, (int)'#', 3);
    mvwprintw(contentWindow, 12, contentWindow->_maxx - 15, " GOING TO ");
    mvwprintw(contentWindow, 13, contentWindow->_maxx - 15, "  FRIDGE  ");
    mvwhline(contentWindow, 11, contentWindow->_maxx - 16, (int)'#', 12);
    mvwhline(contentWindow, 14, contentWindow->_maxx - 16, (int)'#', 12);
    mvwprintw(contentWindow, 15, contentWindow->_maxx - 16, "%s", stream.str().c_str());
    stream.str(std::string()); 

    //DRAW OVENS
    stream << "COOKS:" << std::setw(4) << std::right << GuiNcurses::entityController->GetAmountOfCooksInGivenState(CookState::Cooking);
    mvwvline(contentWindow, 20, contentWindow->_maxx - 7, (int)'#', 3);
    mvwvline(contentWindow, 20, contentWindow->_maxx - 16, (int)'#', 3);
    mvwprintw(contentWindow, 21, contentWindow->_maxx - 15, " OVENS ");
    mvwhline(contentWindow, 20, contentWindow->_maxx - 16, (int)'#', 9);
    mvwhline(contentWindow, 22, contentWindow->_maxx - 16, (int)'#', 9);
    mvwprintw(contentWindow, 23, contentWindow->_maxx - 16, "%s", stream.str().c_str());
    stream.str(std::string());

    //DRAW WALKING COOKS TO BUFFET
    stream << "COOKS:" << std::setw(4) << std::right << GuiNcurses::entityController->GetAmountOfCooksInGivenState(CookState::CookGoingToBuffet);
    mvwvline(contentWindow, 21, 31, (int)'#', 3);
    mvwvline(contentWindow, 21, 42, (int)'#', 3);
    mvwprintw(contentWindow, 21, 32, " GOING TO ");
    mvwprintw(contentWindow, 22, 32, "  BUFFET  ");
    mvwhline(contentWindow, 20, 31, (int)'#', 12);
    mvwhline(contentWindow, 23, 31, (int)'#', 12);
    mvwprintw(contentWindow, 24, 31, "%s", stream.str().c_str());
    stream.str(std::string());

    //DRAW BUFFET
    mvwvline(contentWindow, 20, 5, (int)'#', 3);
    mvwvline(contentWindow, 20, 16, (int)'#', 3);
    mvwprintw(contentWindow, 21, 6, "  BUFFET  ");
    mvwhline(contentWindow, 20, 5, (int)'#', 11);
    mvwhline(contentWindow, 22, 5, (int)'#', 11);
    stream << "CLIENTS:" << std::setw(4) << std::right << GuiNcurses::entityController->GetAmountOfClientsInGivenState(ClientState::ClientWaitingForBuffet);
    mvwprintw(contentWindow, 23, 5, "%s", stream.str().c_str());
    stream.str(std::string());
    stream << "  COOKS:" << std::setw(4) << std::right << GuiNcurses::entityController->GetAmountOfCooksInGivenState(CookState::CookWaitingForBuffet);
    mvwprintw(contentWindow, 24, 5, "%s", stream.str().c_str());
    stream.str(std::string());

    //DRAW WALKING CLIENTS TO BUFFET
    stream << "CLIENTS:" << std::setw(4) << std::right << GuiNcurses::entityController->GetAmountOfClientsInGivenState(ClientState::ClientGoingToBuffet);
    mvwvline(contentWindow, 11, 5, (int)'#', 3);
    mvwvline(contentWindow, 11, 16, (int)'#', 3);
    mvwprintw(contentWindow, 12, 6, " GOING TO ");
    mvwprintw(contentWindow, 13, 6, "  BUFFET  ");
    mvwhline(contentWindow, 11, 5, (int)'#', 12);
    mvwhline(contentWindow, 14, 5, (int)'#', 12);
    mvwprintw(contentWindow, 15, 5, "%s", stream.str().c_str());
    stream.str(std::string());

    //DRAW CANTEEN
    stream << "CLIENTS:" << std::setw(4) << std::right << GuiNcurses::entityController->GetAmountOfClientsInGivenState(ClientState::Eating);
    mvwvline(contentWindow, 3, 5, (int)'#', 3);
    mvwvline(contentWindow, 3, 16, (int)'#', 3);
    mvwprintw(contentWindow, 4, 6, " CANTEEN ");
    mvwhline(contentWindow, 3, 5, (int)'#', 11);
    mvwhline(contentWindow, 5, 5, (int)'#', 11);
    mvwprintw(contentWindow, 6, 5, "%s", stream.str().c_str());
    stream.str(std::string());

    //DRAW MANAGER
    std::string tmp = EntityStateToString(entityController->GetManagerState());
    mvwprintw(contentWindow, 12, 28, "MANAGER STATE:");
    mvwhline(contentWindow, 11, 28, (int)'#', 18);
    mvwhline(contentWindow, 14, 28, (int)'#', 18);
    mvwprintw(contentWindow, 13, 28, "%s", "                "); //clear previous state
    mvwprintw(contentWindow, 13, 28, "%s", tmp.data());

    wrefresh(contentWindow);
}


void GuiNcurses::DrawLeft()
{
    std::stringstream stream;

    mvwprintw(leftWindow, 3, 2, "FRIDGE: ");

    stream << "-Banana:         " << std::setw(4) << std::right << Containers::fridge[PancakeIngredient::Banana] 
            << "/" 
            << Containers::fridgeIngredientLimits[PancakeIngredient::Banana];
    mvwprintw(leftWindow, 4, 2, "%s", stream.str().c_str());
    stream.str(std::string());

    stream << "-Blueberry:      " << std::setw(4) << std::right << Containers::fridge[PancakeIngredient::Blueberry] 
            << "/" 
            << Containers::fridgeIngredientLimits[PancakeIngredient::Blueberry];
    mvwprintw(leftWindow, 5, 2, "%s", stream.str().c_str());
    stream.str(std::string());

    stream << "-Chocolate:      " << std::setw(4) << std::right << Containers::fridge[PancakeIngredient::Chocolate] 
            << "/" 
            << Containers::fridgeIngredientLimits[PancakeIngredient::Chocolate];
    mvwprintw(leftWindow, 6, 2, "%s", stream.str().c_str());
    stream.str(std::string());

    stream << "-Eggs/Milk/Flour:" << std::setw(4) << std::right << Containers::fridge[PancakeIngredient::Eggs_Milk_Flour] 
            << "/" 
            << Containers::fridgeIngredientLimits[PancakeIngredient::Eggs_Milk_Flour];
    mvwprintw(leftWindow, 7, 2, "%s", stream.str().c_str());
    stream.str(std::string());


    mvwprintw(leftWindow, 9, 2, "BUFFET: ");

    stream << "  Pancakes " << std::setw(4) << std::right << Containers::buffet[PancakeType::BananaPancakes] 
            << "/" 
            << Containers::buffetPancakesLimits[PancakeType::BananaPancakes];
    mvwprintw(leftWindow, 10, 2, "-Banana ");
    mvwprintw(leftWindow, 11, 2, "%s", stream.str().c_str());
    stream.str(std::string());

    stream << "  Pancakes " << std::setw(4) << std::right << Containers::buffet[PancakeType::BlueberryPancakes] 
            << "/" 
            << Containers::buffetPancakesLimits[PancakeType::BlueberryPancakes];
    mvwprintw(leftWindow, 12, 2, "-Blueberry ");
    mvwprintw(leftWindow, 13, 2, "%s", stream.str().c_str());
    stream.str(std::string());


    stream << "  Pancakes " << std::setw(4) << std::right << Containers::buffet[PancakeType::ChocolatePancakes] 
            << "/" 
            << Containers::buffetPancakesLimits[PancakeType::ChocolatePancakes];
    mvwprintw(leftWindow, 14, 2, "-Chocolate ");
    mvwprintw(leftWindow, 15, 2, "%s", stream.str().c_str());
    stream.str(std::string());


    wrefresh(leftWindow);
}


GuiNcurses::GuiNcurses(EntityController& entityController)
{
    GuiNcurses::entityController = &entityController;

    initscr();

    contentWindow  = newwin(WINDOW_HEIGHT*9/10, WINDOW_WIDTH*60/100, WINDOW_START_Y, WINDOW_START_X + WINDOW_WIDTH*25/100);
    bottomWindow = newwin(WINDOW_HEIGHT*1/10, WINDOW_WIDTH * 85/100, WINDOW_HEIGHT*9/10, WINDOW_START_X);
    leftWindow = newwin(WINDOW_HEIGHT*9/10, WINDOW_WIDTH*25/100, WINDOW_START_Y, WINDOW_START_X);
    rightWindow = newwin(WINDOW_HEIGHT, WINDOW_WIDTH*15/100, WINDOW_START_Y, WINDOW_START_X + WINDOW_WIDTH*85/100);
    refresh();

    box(contentWindow, 0, 0);
    box(bottomWindow, 0, 0);
    box(leftWindow, 0, 0);
    box(rightWindow, 0, 0);

    mvwprintw(contentWindow, 1, 2, "RESTAURANT");
    mvwprintw(leftWindow, 1, 2, "CONTAINERS");
    mvwprintw(bottomWindow, 1, 2, "USER INPUT: ");
    mvwprintw(rightWindow, 1, 2, "COMMANDS");

    wrefresh(contentWindow);
    wrefresh(bottomWindow);
    wrefresh(leftWindow);
    wrefresh(rightWindow);

    DrawContent();
    DrawLeft();
    DrawRight();
}

GuiNcurses::~GuiNcurses()
{
}


void GuiNcurses::RunGui()
{
    while (true)
    {
        DrawContent();
        DrawLeft();

        std::this_thread::sleep_for(std::chrono::milliseconds(34));
    }
    endwin();
}