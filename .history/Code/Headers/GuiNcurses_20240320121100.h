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

public:
    GuiNcurses(/* args */);
    ~GuiNcurses();

    void RunGui();
    
    void Setup();
};

GuiNcurses::GuiNcurses(/* args */)
{
}

GuiNcurses::~GuiNcurses()
{
}


WINDOW* GuiNcurses::contentWindow;
WINDOW* GuiNcurses::bottomWindow;
WINDOW* GuiNcurses::leftWindow;

void GuiNcurses::RunGui()
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

    wrefresh(contentWindow);
    wrefresh(bottomWindow);
    wrefresh(leftWindow);

    getch();
    endwin();
}