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

    //DRAW WALKING COOKS TO FRIDGE
    mvwvline(contentWindow, 11, contentWindow->_maxx - 8, (int)'#', 3);
    mvwvline(contentWindow, 11, contentWindow->_maxx - 19, (int)'#', 3);
    mvwprintw(contentWindow, 12, contentWindow->_maxx - 18, " GOING TO ");
    mvwprintw(contentWindow, 13, contentWindow->_maxx - 18, "  FRIDGE  ");
    mvwhline(contentWindow, 11, contentWindow->_maxx - 19, (int)'#', 12);
    mvwhline(contentWindow, 14, contentWindow->_maxx - 19, (int)'#', 12);
    mvwprintw(contentWindow, 15, contentWindow->_maxx - 19, "COOKS: ???"); 

    //DRAW OVENS
    mvwvline(contentWindow, 21, contentWindow->_maxx - 10, (int)'#', 3);
    mvwvline(contentWindow, 21, contentWindow->_maxx - 19, (int)'#', 3);
    mvwprintw(contentWindow, 22, contentWindow->_maxx - 18, " OVENS ");
    mvwhline(contentWindow, 21, contentWindow->_maxx - 19, (int)'#', 9);
    mvwhline(contentWindow, 23, contentWindow->_maxx - 19, (int)'#', 9);
    mvwprintw(contentWindow, 24, contentWindow->_maxx - 19, "COOKS: ???");

    //DRAW WALKING COOKS TO BUFFET
    mvwvline(contentWindow, 21, 25, (int)'#', 3);
    mvwvline(contentWindow, 21, 36, (int)'#', 3);
    mvwprintw(contentWindow, 21, 26, " GOING TO ");
    mvwprintw(contentWindow, 22, 26, "  BUFFET  ");
    mvwhline(contentWindow, 20, 25, (int)'#', 12);
    mvwhline(contentWindow, 23, 25, (int)'#', 12);
    mvwprintw(contentWindow, 24, 25, "COOKS: ???");

    //DRAW BUFFET
    mvwvline(contentWindow, 20, 5, (int)'#', 3);
    mvwvline(contentWindow, 20, 16, (int)'#', 3);
    mvwprintw(contentWindow, 21, 6, "  BUFFET  ");
    mvwhline(contentWindow, 20, 5, (int)'#', 11);
    mvwhline(contentWindow, 22, 5, (int)'#', 11);
    mvwprintw(contentWindow, 23, 5, "CLIENTS: ???");
    mvwprintw(contentWindow, 24, 5, "COOKS:   ???");



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