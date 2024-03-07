#include <iostream>
#include <vector>
#include <mutex>
#include <condition_variable>
#include "Headers/Cook.h"
#include "Headers/PancakesTypes.h"
#include "Headers/Manager.h"




std::mutex buffetMutex;
std::mutex fridgeMutex;


int main(int argc, char const *argv[])
{
    Manager manager(10, 20, 30);

    std::this_thread::sleep_for(std::chrono::seconds(1));


    manager.CreateAndRunCook(buffetMutex, PancakeType::BananaPancakes);
    manager.CreateAndRunCook(buffetMutex, PancakeType::ChocolatePancakes);
    manager.CreateAndRunCook(buffetMutex, PancakeType::BlueberryPancakes);

    std::this_thread::sleep_for(std::chrono::seconds(15));

    std::cout<< "Buffet size: " << std::endl << 
    "Banana: "<< buffet[PancakeType::BananaPancakes] << std::endl <<
    "Chocolate: "<< buffet[PancakeType::ChocolatePancakes] << std::endl <<
    "Blueberry: "<< buffet[PancakeType::BlueberryPancakes] << std::endl;

    return 0;
}
