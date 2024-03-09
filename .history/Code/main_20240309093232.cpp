#include <iostream>
#include <vector>
#include <mutex>
#include <condition_variable>
#include "Headers/PancakesTypes.h"
#include "Headers/RestaurantContainers.h"
#include "Headers/EntityController.h"
#include "Headers/Gui.h"
#include <algorithm>


int main(int argc, char const *argv[])
{
    EntityController entityController;

    entityController.RunManager(10);
    entityController.AddCook(PancakeType::BananaPancakes, 1000, 2000);
    entityController.AddCook(PancakeType::BananaPancakes, 1000, 2000);
    entityController.AddCook(PancakeType::BananaPancakes, 1000, 2000);
    entityController.AddCook(PancakeType::BananaPancakes, 1000, 2000);
    entityController.AddCook(PancakeType::ChocolatePancakes, 1000, 2000);
    entityController.AddCook(PancakeType::ChocolatePancakes, 1000, 2000);
    entityController.AddCook(PancakeType::ChocolatePancakes, 1000, 2000);
    entityController.AddCook(PancakeType::ChocolatePancakes, 1000, 2000);
    entityController.AddCook(PancakeType::BlueberryPancakes, 1000, 2000);
    entityController.AddCook(PancakeType::BlueberryPancakes, 1000, 2000);
    entityController.AddCook(PancakeType::BlueberryPancakes, 1000, 2000);
    entityController.AddCook(PancakeType::BlueberryPancakes, 1000, 2000);
    entityController.AddClient(1000, 2000);
    entityController.AddClient(1000, 2000);
    entityController.AddClient(1000, 2000);
    entityController.AddClient(1000, 2000);
    entityController.AddClient(1000, 2000);

    Gui::RunGui(entityController, 1);
    
    while (Gui::UserInput != "exit")
    {
        std::string input;
        std::getline(std::cin, input);
        
        sstr.erase(std::remove(str.begin(), str.end(), '\n'), str.end());
        sstr.erase(std::remove(str.begin(), str.end(), '\t'), str.end());
        sstr.erase(std::remove(str.begin(), str.end(), '\r'), str.end());
        sstr.erase(std::remove(str.begin(), str.end(), ' '), str.end());

        Gui::UserInput = input;


        if(Gui::UserInput == "add cook banana")
        {
            entityController.AddCook(PancakeType::BananaPancakes, 1000, 2000);
        }
        else if(Gui::UserInput == "add cook chocolate")
        {
            entityController.AddCook(PancakeType::ChocolatePancakes, 1000, 2000);
        }
        else if(Gui::UserInput == "add cook blueberry")
        {
            entityController.AddCook(PancakeType::BlueberryPancakes, 1000, 2000);
        }
        else if(Gui::UserInput == "add client")
        {
            entityController.AddClient(1000, 2000);
        }
        else if (Gui::UserInput == "delete client")
        {
            entityController.DeleteClient();
        }
        else if (Gui::UserInput == "delete cook")
        {
            //entityController.DeleteCook();
        }
        
    }

    return 0;
}
