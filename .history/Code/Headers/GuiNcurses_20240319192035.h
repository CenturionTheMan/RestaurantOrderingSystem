#include <curses.h>


namespace GuiNcurses
{

    const int WINDOW_HEIGHT = 10;
    const int WINDOW_WIDTH = 10;
    
    void RunGui();





} // namespace GuiNcurses



void GuiNcurses::RunGui()
{
    initscr();

    




    getch();
    endwin();
}
