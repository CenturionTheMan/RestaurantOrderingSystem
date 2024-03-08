#include <iostream>
#include <vector>
#include <mutex>
#include <condition_variable>
#include "Headers/Cook.h"
#include "Headers/PancakesTypes.h"
#include "Headers/Manager.h"
#include "Headers/RestaurantContainers.h"
#include "Headers/Client.h"





int main(int argc, char const *argv[])
{
    Manager manager(10);
    manager.Run();

    Cook cook1(manager, PancakeType::BananaPancakes, 1000, 3000);
    cook1.Run();

    Client client1(1000, 3000);
    client1.Run();



    std::this_thread::sleep_for(std::chrono::seconds(15));

    std::cout<< "Buffet size: " << std::endl << 
    "Banana: "<< Containers::buffet[PancakeType::BananaPancakes] << std::endl <<
    "Chocolate: "<< Containers::buffet[PancakeType::ChocolatePancakes] << std::endl <<
    "Blueberry: "<< Containers::buffet[PancakeType::BlueberryPancakes] << std::endl;

    return 0;
}
