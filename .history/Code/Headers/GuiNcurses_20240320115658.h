#pragma once

#include <ncurses.h>


namespace GuiNcurses
{
    void RunGui();


} // namespace GuiNcurses


void GuiNcurses::RunGui()
{
    initscr();

    WINDOW* containerWindow  = newwin(WINDOW_HEIGHT, WINDOW_WIDTH, WINDOW_START_Y, WINDOW_START_X);

    wrefresh(containerWindow);


    refresh();
    getch();
    endwin();
}