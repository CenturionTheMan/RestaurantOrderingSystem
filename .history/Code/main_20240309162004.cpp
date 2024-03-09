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
        
        Gui::UserInput = input;

        input.erase(std::remove(input.begin(), input.end(), '\n'), input.end());
        input.erase(std::remove(input.begin(), input.end(), '\t'), input.end());
        input.erase(std::remove(input.begin(), input.end(), '\r'), input.end());
        input.erase(std::remove(input.begin(), input.end(), ' '), input.end());



        if(input == "addcookbanana")
        {
            entityController.AddCook(PancakeType::BananaPancakes, 1000, 2000);
        }
        else if(input == "addcookchocolate")
        {
            entityController.AddCook(PancakeType::ChocolatePancakes, 1000, 2000);
        }
        else if(input == "addcookblueberry")
        {
            entityController.AddCook(PancakeType::BlueberryPancakes, 1000, 2000);
        }
        else if(input == "addclient")
        {
            entityController.AddClient(1000, 2000);
        }
        else if (input == "deleteclient")
        {
            entityController.DeleteClient(); //!! will crash
        }
        else if (input == "deletecook")
        {
            //entityController.DeleteCook();
        }
        
    }

    return 0;
}
