#include "../Headers/GuiNcurses.h"


#pragma region CTOR/DTOR


GuiNcurses::GuiNcurses(EntityController& entityController)
{
    GuiNcurses::entityController = &entityController;

    initscr();

    cbreak();
    noecho();

    contentWindow  = newwin(WINDOW_HEIGHT*9/10, WINDOW_WIDTH*50/100, WINDOW_START_Y, WINDOW_START_X + WINDOW_WIDTH*25/100);
    bottomWindow = newwin(WINDOW_HEIGHT*1/10, WINDOW_WIDTH * 75/100, WINDOW_HEIGHT*9/10, WINDOW_START_X);
    leftWindow = newwin(WINDOW_HEIGHT*9/10, WINDOW_WIDTH*25/100, WINDOW_START_Y, WINDOW_START_X);
    rightWindow = newwin(WINDOW_HEIGHT, WINDOW_WIDTH*25/100, WINDOW_START_Y, WINDOW_START_X + WINDOW_WIDTH*75/100);
    refresh();

    box(contentWindow, 0, 0);
    box(bottomWindow, 0, 0);
    box(leftWindow, 0, 0);
    box(rightWindow, 0, 0);

    mvwprintw(contentWindow, 1, 2, "|RESTAURANT|");
    mvwprintw(leftWindow, 1, 2, "|CONTAINERS|");
    // mvwprintw(bottomWindow, 1, 2, "USER INPUT > ");
    mvwprintw(rightWindow, 1, 2, "|COMMANDS|");

    wrefresh(contentWindow);
    wrefresh(bottomWindow);
    wrefresh(leftWindow);
    wrefresh(rightWindow);

    DrawContent();
    DrawLeft();
    DrawRight();
    DrawBottom();
}

GuiNcurses::~GuiNcurses()
{
}

#pragma endregion CTOR/DTOR


#pragma region PRIVATE_METHODS


#pragma endregion PRIVATE_METHODS