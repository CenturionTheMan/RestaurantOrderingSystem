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
    const int WINDOW_WIDTH = 120;
    const int WINDOW_START_X = 0;
    const int WINDOW_START_Y = 0;
    
    WINDOW* contentWindow;
    WINDOW* bottomWindow;
    WINDOW* leftWindow;
    WINDOW* rightWindow;

    EntityController* entityController;

    void DrawContent();
    void DrawLeft();

public:
    GuiNcurses(EntityController& entityController);
    ~GuiNcurses();

    void RunGui();
    
};

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
    mvwvline(contentWindow, 20, contentWindow->_maxx - 7, (int)'#', 3);
    mvwvline(contentWindow, 20, contentWindow->_maxx - 16, (int)'#', 3);
    mvwprintw(contentWindow, 21, contentWindow->_maxx - 15, " OVENS ");
    mvwhline(contentWindow, 20, contentWindow->_maxx - 16, (int)'#', 9);
    mvwhline(contentWindow, 22, contentWindow->_maxx - 16, (int)'#', 9);
    mvwprintw(contentWindow, 23, contentWindow->_maxx - 16, "COOKS: ???");

    //DRAW WALKING COOKS TO BUFFET
    mvwvline(contentWindow, 21, 31, (int)'#', 3);
    mvwvline(contentWindow, 21, 42, (int)'#', 3);
    mvwprintw(contentWindow, 21, 32, " GOING TO ");
    mvwprintw(contentWindow, 22, 32, "  BUFFET  ");
    mvwhline(contentWindow, 20, 31, (int)'#', 12);
    mvwhline(contentWindow, 23, 31, (int)'#', 12);
    mvwprintw(contentWindow, 24, 31, "COOKS: ???");

    //DRAW BUFFET
    mvwvline(contentWindow, 20, 5, (int)'#', 3);
    mvwvline(contentWindow, 20, 16, (int)'#', 3);
    mvwprintw(contentWindow, 21, 6, "  BUFFET  ");
    mvwhline(contentWindow, 20, 5, (int)'#', 11);
    mvwhline(contentWindow, 22, 5, (int)'#', 11);
    mvwprintw(contentWindow, 23, 5, "CLIENTS: ???");
    mvwprintw(contentWindow, 24, 5, "COOKS:   ???");

    //DRAW WALKING CLIENTS TO BUFFET
    mvwvline(contentWindow, 11, 5, (int)'#', 3);
    mvwvline(contentWindow, 11, 16, (int)'#', 3);
    mvwprintw(contentWindow, 12, 6, " GOING TO ");
    mvwprintw(contentWindow, 13, 6, "  BUFFET  ");
    mvwhline(contentWindow, 11, 5, (int)'#', 12);
    mvwhline(contentWindow, 14, 5, (int)'#', 12);
    mvwprintw(contentWindow, 15, 5, "CLIENTS: ???");

    //DRAW CANTEEN
    mvwvline(contentWindow, 3, 5, (int)'#', 3);
    mvwvline(contentWindow, 3, 16, (int)'#', 3);
    mvwprintw(contentWindow, 4, 6, " CANTEEN ");
    mvwhline(contentWindow, 3, 5, (int)'#', 11);
    mvwhline(contentWindow, 5, 5, (int)'#', 11);
    mvwprintw(contentWindow, 6, 5, "CLIENTS: ???");


    //DRAW MANAGER
    mvwprintw(contentWindow, 12, 28, "MANAGER STATE:");
    mvwhline(contentWindow, 11, 28, (int)'#', 18);
    mvwhline(contentWindow, 14, 28, (int)'#', 18);
    mvwprintw(contentWindow, 13, 28, "adding ingredients");

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

        std::this_thread::sleep_for(std::chrono::milliseconds(68));
    }
    endwin();
}