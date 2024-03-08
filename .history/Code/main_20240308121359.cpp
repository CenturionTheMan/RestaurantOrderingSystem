#include <iostream>
#include <vector>
#include <mutex>
#include <condition_variable>
#include "Headers/PancakesTypes.h"
#include "Headers/RestaurantContainers.h"
#include "Headers/EntityController.h"




int main(int argc, char const *argv[])
{
    EntityController entityController(10);

    entityController.RunManager(1;
    entityController.AddCook(PancakeType::BananaPancakes, 1000, 2000);
    entityController.AddClient(1000, 2000);

    std::this_thread::sleep_for(std::chrono::seconds(15));

    std::cout<< "Buffet size: " << std::endl << 
    "Banana: "<< Containers::buffet[PancakeType::BananaPancakes] << std::endl <<
    "Chocolate: "<< Containers::buffet[PancakeType::ChocolatePancakes] << std::endl <<
    "Blueberry: "<< Containers::buffet[PancakeType::BlueberryPancakes] << std::endl;

    return 0;
}
