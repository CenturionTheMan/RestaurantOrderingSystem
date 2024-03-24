#pragma once

#include <ncurses.h>
#include "EntityController.h"
#include "RestaurantContainers.h"
#include <string>

class GuiNcurses
{
private:
    const int WINDOW_HEIGHT = 30;
    const int WINDOW_WIDTH = 100;
    const int WINDOW_START_X = 0;
    const int WINDOW_START_Y = 0;
    
    WINDOW* contentWindow;
    WINDOW* bottomWindow;
    WINDOW* leftWindow;

    void DrawContent();
    void DrawLeft();

public:
    GuiNcurses(/* args */);
    ~GuiNcurses();

    void RunGui();
    
};

void GuiNcurses::DrawContent()
{
    //DRAW FRIDGE
    mvwvline(contentWindow, 3, contentWindow->_maxx - 7, (int)'#', 3);
    mvwvline(contentWindow, 3, contentWindow->_maxx - 16, (int)'#', 3);
    mvwprintw(contentWindow, 4, contentWindow->_maxx - 15, " FRIDGE ");
    mvwhline(contentWindow, 3, contentWindow->_maxx - 16, (int)'#', 9);
    mvwhline(contentWindow, 5, contentWindow->_maxx - 16, (int)'#', 9);
    mvwprintw(contentWindow, 6, contentWindow->_maxx - 16, "COOKS: ???");

    //DRAW WALKING COOKS TO FRIDGE
    mvwvline(contentWindow, 11, contentWindow->_maxx - 5, (int)'#', 3);
    mvwvline(contentWindow, 11, contentWindow->_maxx - 16, (int)'#', 3);
    mvwprintw(contentWindow, 12, contentWindow->_maxx - 15, " GOING TO ");
    mvwprintw(contentWindow, 13, contentWindow->_maxx - 15, "  FRIDGE  ");
    mvwhline(contentWindow, 11, contentWindow->_maxx - 16, (int)'#', 12);
    mvwhline(contentWindow, 14, contentWindow->_maxx - 16, (int)'#', 12);
    mvwprintw(contentWindow, 15, contentWindow->_maxx - 16, "COOKS: ???"); 

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
    std::string bananaStr = "-Banana: " + std::to_string(Containers::fridge[PancakeIngredient::Banana]) + " / " + std::to_string(Containers::fridgeIngredientLimits[PancakeIngredient::Banana]);
    std::string blueberryStr = "-Blueberry: " + std::to_string(Containers::fridge[PancakeIngredient::Blueberry]) + " / " + std::to_string(Containers::fridgeIngredientLimits[PancakeIngredient::Blueberry]);
    std::string chocolateStr = "-Chocolate: " + std::to_string(Containers::fridge[PancakeIngredient::Chocolate]) + " / " + std::to_string(Containers::fridgeIngredientLimits[PancakeIngredient::Chocolate]);
    std::string commonsStr = "-Eggs/Milk/Flour: " + std::to_string(Containers::fridge[PancakeIngredient::Eggs_Milk_Flour]) + " / " + std::to_string(Containers::fridgeIngredientLimits[PancakeIngredient::Eggs_Milk_Flour]);
    mvwprintw(leftWindow, 3, 2, "FRIDGE: ");
    mvwprintw(leftWindow, 4, 2, "%s", bananaStr.);
    mvwprintw(leftWindow, 5, 2, "%s", blueberryStr.c_str());
    mvwprintw(leftWindow, 6, 2, "%s", chocolateStr.c_str());
    mvwprintw(leftWindow, 7, 2, "%s", commonsStr.c_str());

    wrefresh(leftWindow);
}

GuiNcurses::GuiNcurses()
{
    initscr();

    contentWindow  = newwin(WINDOW_HEIGHT-WINDOW_HEIGHT/9, WINDOW_WIDTH-WINDOW_WIDTH/4, WINDOW_START_Y, WINDOW_START_X + WINDOW_WIDTH/4);
    bottomWindow = newwin(WINDOW_HEIGHT/9, WINDOW_WIDTH - WINDOW_WIDTH/4, WINDOW_HEIGHT - WINDOW_HEIGHT/9, WINDOW_START_X);
    leftWindow = newwin(WINDOW_HEIGHT - WINDOW_HEIGHT/9, WINDOW_WIDTH/4, WINDOW_START_Y, WINDOW_START_X);
    refresh();

    box(contentWindow, 0, 0);
    box(bottomWindow, 0, 0);
    box(leftWindow, 0, 0);

    mvwprintw(contentWindow, 1, 2, "RESTAURANT");
    mvwprintw(leftWindow, 1, 2, "CONTAINERS");
    mvwprintw(bottomWindow, 1, 2, "USER INPUT: ");

    wrefresh(contentWindow);
    wrefresh(bottomWindow);
    wrefresh(leftWindow);

    DrawContent();
    DrawLeft();

    getch();
    endwin();
}

GuiNcurses::~GuiNcurses()
{
}


void GuiNcurses::RunGui()
{
    
}