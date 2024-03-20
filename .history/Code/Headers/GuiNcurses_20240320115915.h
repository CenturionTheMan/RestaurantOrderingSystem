#pragma once

#include <ncurses.h>


namespace GuiNcurses
{
    const int WINDOW_HEIGHT = 30;
    const int WINDOW_WIDTH = 100;
    const int WINDOW_START_X = 0;
    const int WINDOW_START_Y = 0;
    

    void RunGui();


} // namespace GuiNcurses


void GuiNcurses::RunGui()
{
    initscr();

    WINDOW* containerWindow  = newwin(WINDOW_HEIGHT, WINDOW_WIDTH, WINDOW_START_Y, WINDOW_START_X);
    box(containerWindow, 0, 0);

    WINDOW* bottomWindow = newwin(WINDOW_HEIGHT/10, WINDOW_WIDTH, WINDOW_HEIGHT - WINDOW_HEIGHT/10, WINDOW_START_X);
    box(bottomWindow, 0, 0);

    refresh();
    wrefresh(containerWindow);
    wrefresh(bottomWindow);
    getch();
    endwin();
}