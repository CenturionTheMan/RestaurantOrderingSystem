#include "Headers/PancakesTypes.h"
#include "Headers/RestaurantContainers.h"
#include "Headers/EntityController.h"
#include "Headers/Gui.h"
#include "Headers/GuiNcurses.h"


int main(int argc, char const *argv[])
{
    EntityController entityController;

    entityController.RunManager(10);
    entityController.AddCook(PancakeType::BananaPancakes, 1000, 2000);
    entityController.AddCook(PancakeType::ChocolatePancakes, 1000, 2000);
    entityController.AddCook(PancakeType::BlueberryPancakes, 1000, 2000);
    entityController.AddClient(1000, 2000);
    entityController.AddClient(1000, 2000);
    entityController.AddClient(1000, 2000);
    #ifdef _WIN32 or _WIN64
    #else _UNIX
    std::system("clear"); //! linux
    #endif
    // Gui::RunGuiOutput(entityController, 68); //around 15 frames per second
    // Gui::RunGuiInput(entityController);
    
    GuiNcurses gui(entityController);
    gui.RunGui();
    return 0;
}
