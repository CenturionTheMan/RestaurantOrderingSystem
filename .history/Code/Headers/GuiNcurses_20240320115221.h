#pragma once

#include <ncurses.h>


namespace GuiNcurses
{
    const int WINDOW_HEIGHT = 20;
    const int WINDOW_WIDTH = 150;
    const int WINDOW_START_X = 0;
    const int WINDOW_START_Y = 0;
    

    void RunGui();


} // namespace GuiNcurses


void GuiNcurses::RunGui()
{
    initscr();

    WINDOW* win  = newwin(WINDOW_HEIGHT, WINDOW_WIDTH, WINDOW_START_Y, WINDOW_START_X);
    refresh();

    box(win, 0, 0);
    wrefresh(win);

    getch();
    endwin();
}