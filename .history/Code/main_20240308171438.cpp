#include <iostream>
#include <vector>
#include <mutex>
#include <condition_variable>
#include "Headers/PancakesTypes.h"
#include "Headers/RestaurantContainers.h"
#include "Headers/EntityController.h"
#include "Headers/Gui.h"



int main(int argc, char const *argv[])
{
    EntityController entityController;

    entityController.RunManager(10);
    entityController.AddCook(PancakeType::BananaPancakes, 1000, 2000);
    entityController.AddCook(PancakeType::ChocolatePancakes, 1000, 2000);
    entityController.AddCook(PancakeType::BlueberryPancakes, 1000, 2000);
    entityController.AddClient(1000, 2000);

    Gui::RunGui(entityController, 1);


    std::cin.get();

    return 0;
}
