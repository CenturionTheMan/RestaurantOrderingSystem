#pragma once

#include <ncurses.h>


namespace GuiNcurses
{
    const int WINDOW_HEIGHT = 30;
    const int WINDOW_WIDTH = 100;
    const int WINDOW_START_X = 0;
    const int WINDOW_START_Y = 0;
    
    WINDOW* contentWindow  = newwin(WINDOW_HEIGHT-WINDOW_HEIGHT/10, WINDOW_WIDTH-WINDOW_WIDTH/4, WINDOW_START_Y, WINDOW_START_X + WINDOW_WIDTH/4);
    WINDOW* bottomWindow = newwin(WINDOW_HEIGHT/10, WINDOW_WIDTH - WINDOW_WIDTH/4, WINDOW_HEIGHT - WINDOW_HEIGHT/10, WINDOW_START_X + WINDOW_WIDTH/4);
    WINDOW* leftWindow = newwin(WINDOW_HEIGHT, WINDOW_WIDTH/4, WINDOW_START_Y, WINDOW_START_X);

    void RunGui();


} // namespace GuiNcurses


void GuiNcurses::RunGui()
{
    initscr();

    
    refresh();

    box(contentWindow, 0, 0);
    box(bottomWindow, 0, 0);
    box(leftWindow, 0, 0);

    mvwprintw(contentWindow, 1, 2, "RESTAURANT");
    mvwprintw(leftWindow, 1, 2, "COMMANDS: ");

    wrefresh(contentWindow);
    wrefresh(bottomWindow);
    wrefresh(leftWindow);

    getch();
    endwin();
}