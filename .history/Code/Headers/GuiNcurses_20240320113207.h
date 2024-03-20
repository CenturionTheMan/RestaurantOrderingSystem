#pragma once

#include <ncurses.h>


namespace GuiNcurses
{
    const int WINDOW_HEIGHT = 20;
    const int WINDOW_WIDTH = 20;
    const int WINDOW_START_X = 20;
    const int WINDOW_START_Y = 20;
    

    void RunGui();


} // namespace GuiNcurses


void GuiNcurses::RunGui()
{
    initscr();

    WINDOW* win  = newwin(WINDOW_HEIGHT, WINDOW_WIDTH, WINDOW_START_Y, WINDOW_START_X);
    refresh();

    box(win, 0, 0);

    getch();
    endwin();
}