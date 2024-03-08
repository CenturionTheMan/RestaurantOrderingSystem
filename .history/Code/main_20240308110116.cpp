#include <iostream>
#include <vector>
#include <mutex>
#include <condition_variable>
#include "Headers/Cook.h"
#include "Headers/PancakesTypes.h"
#include "Headers/Manager.h"
#include "Headers/RestaurantContainers.h"






int main(int argc, char const *argv[])
{
    Manager manager;

    Cook cook1(manager, PancakeType::BananaPancakes, 1000, 3000);
    cook1.Run(manager.bananaPancakesLimitCondition);

    // manager.CreateAndRunCook(PancakeType::BananaPancakes);
    // manager.CreateAndRunCook(PancakeType::ChocolatePancakes);
    // manager.CreateAndRunCook(PancakeType::BlueberryPancakes);

    std::this_thread::sleep_for(std::chrono::seconds(5));

    manager.Run();

    std::this_thread::sleep_for(std::chrono::seconds(15));

    std::cout<< "Buffet size: " << std::endl << 
    "Banana: "<< Containers::buffet[PancakeType::BananaPancakes] << std::endl <<
    "Chocolate: "<< Containers::buffet[PancakeType::ChocolatePancakes] << std::endl <<
    "Blueberry: "<< Containers::buffet[PancakeType::BlueberryPancakes] << std::endl;

    return 0;
}
