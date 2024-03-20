#include "Headers/PancakesTypes.h"
#include "Headers/RestaurantContainers.h"
#include "Headers/EntityController.h"
#include "Headers/Gui.h"
// #include "Headers/GuiNcurses.h"
#include <ncurses.h>


int main(int argc, char const *argv[])
{
    // EntityController entityController;

    // entityController.RunManager(10);
    // entityController.AddCook(PancakeType::BananaPancakes, 1000, 2000);
    // entityController.AddCook(PancakeType::ChocolatePancakes, 1000, 2000);
    // entityController.AddCook(PancakeType::BlueberryPancakes, 1000, 2000);
    // entityController.AddClient(1000, 2000);
    // entityController.AddClient(1000, 2000);
    // entityController.AddClient(1000, 2000);

    // Gui::RunGuiOutput(entityController, 68); //around 15 frames per second
    
    // Gui::RunGuiInput(entityController);


    initscr();

    WINDOW* win  = newwin(20, 20, 10, 10r);


    endwin();
    return 0;
}
