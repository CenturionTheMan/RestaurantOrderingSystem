#pragma once

#include <ncurses.h>

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

public:
    GuiNcurses(/* args */);
    ~GuiNcurses();

    void RunGui();
    
};

void GuiNcurses::DrawContent()
{
    //DRAW FRIDGE
    mvwvline(contentWindow, 2, contentWindow->_maxx - 10, (int)'#', 3);
    mvwvline(contentWindow, 2, contentWindow->_maxx - 19, (int)'#', 3);
    mvwprintw(contentWindow, 3, contentWindow->_maxx - 18, " FRIDGE ");
    mvwhline(contentWindow, 2, contentWindow->_maxx - 19, (int)'#', 9);
    mvwhline(contentWindow, 4, contentWindow->_maxx - 19, (int)'#', 9);
    mvwprintw(contentWindow, 5, contentWindow->_maxx - 19, "COOKS: ???");

    //DRAW WALKING COOKS
    mvwvline(contentWindow, 2, contentWindow->_maxx - 10, (int)'#', 3);
    mvwvline(contentWindow, 2, contentWindow->_maxx - 19, (int)'#', 3);
    mvwprintw(contentWindow, 3, contentWindow->_maxx - 18, " GOING TO \n FRIDGE ");
    mvwhline(contentWindow, 2, contentWindow->_maxx - 19, (int)'#', 9);
    mvwhline(contentWindow, 4, contentWindow->_maxx - 19, (int)'#', 9);
    mvwprintw(contentWindow, 5, contentWindow->_maxx - 19, "COOKS: ???"); 


    //DRAW OVENS
    mvwvline(contentWindow, 21, contentWindow->_maxx - 10, (int)'#', 3);
    mvwvline(contentWindow, 21, contentWindow->_maxx - 19, (int)'#', 3);
    mvwprintw(contentWindow, 22, contentWindow->_maxx - 18, " OVENS ");
    mvwhline(contentWindow, 21, contentWindow->_maxx - 19, (int)'#', 9);
    mvwhline(contentWindow, 23, contentWindow->_maxx - 19, (int)'#', 9);
    mvwprintw(contentWindow, 24, contentWindow->_maxx - 19, "COOKS: ???");


    


    wrefresh(contentWindow);
}

GuiNcurses::GuiNcurses()
{
    initscr();

    contentWindow  = newwin(WINDOW_HEIGHT-WINDOW_HEIGHT/10, WINDOW_WIDTH-WINDOW_WIDTH/4, WINDOW_START_Y, WINDOW_START_X + WINDOW_WIDTH/4);
    bottomWindow = newwin(WINDOW_HEIGHT/10, WINDOW_WIDTH - WINDOW_WIDTH/4, WINDOW_HEIGHT - WINDOW_HEIGHT/10, WINDOW_START_X + WINDOW_WIDTH/4);
    leftWindow = newwin(WINDOW_HEIGHT, WINDOW_WIDTH/4, WINDOW_START_Y, WINDOW_START_X);
    refresh();

    box(contentWindow, 0, 0);
    box(bottomWindow, 0, 0);
    box(leftWindow, 0, 0);

    mvwprintw(contentWindow, 1, 2, "RESTAURANT");
    mvwprintw(leftWindow, 1, 2, "COMMANDS: ");
    mvwprintw(bottomWindow, 1, 2, "USER INPUT: ");

    wrefresh(contentWindow);
    wrefresh(bottomWindow);
    wrefresh(leftWindow);

    DrawContent();

    getch();
    endwin();
}

GuiNcurses::~GuiNcurses()
{
}


void GuiNcurses::RunGui()
{
    
}