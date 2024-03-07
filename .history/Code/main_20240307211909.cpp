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
    Manager manager(10, 20, 30);

    std::this_thread::sleep_for(std::chrono::seconds(1));

    manager.CreateAndRunCook(PancakeType::BananaPancakes);

    std::this_thread::sleep_for(std::chrono::seconds(15));

    std::cout<< "Buffet size: " << std::endl << 
    "Banana: "<< Containers::buffet[PancakeType::BananaPancakes] << std::endl <<
    "Chocolate: "<< Containers::buffet[PancakeType::ChocolatePancakes] << std::endl <<
    "Blueberry: "<< Containers::buffet[PancakeType::BlueberryPancakes] << std::endl;

    return 0;
}
