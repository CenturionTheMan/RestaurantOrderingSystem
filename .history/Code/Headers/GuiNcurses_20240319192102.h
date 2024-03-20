#include <curses.h>


namespace GuiNcurses
{

    const int WINDOW_HEIGHT = 10;
    const int WINDOW_WIDTH = 20;
    const int WINDOW_START_Y = 0;
    const int WINDOW_START_X = 0;
    
    void RunGui();





} // namespace GuiNcurses



void GuiNcurses::RunGui()
{
    initscr();

    




    getch();
    endwin();
}
