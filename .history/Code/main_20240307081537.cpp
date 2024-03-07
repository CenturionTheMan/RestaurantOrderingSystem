#include <iostream>
#include <vector>
#include <mutex>
#include <condition_variable>
#include "Headers/Cook.h"
#include "Headers/PancakesTypes.h"
#include "Headers/Manager.h"


static std::map<PancakeType, int> buffet = {
    {PancakeType::BananaPancakes, 0},
    {PancakeType::BlueberryPancakes, 0},
    {PancakeType::ChocolatePancakes, 0}
};

static std::map<PancakeType, int> fridge = {
    {PancakeType::BananaPancakes, 10},
    {PancakeType::BlueberryPancakes, 20},
    {PancakeType::ChocolatePancakes, 30}
};

std::mutex buffetMutex;


int main(int argc, char const *argv[])
{
    Manager manager(10, 20, 30);

    std::this_thread::sleep_for(std::chrono::seconds(1));


    manager.CreateAndRunCook(buffet, buffetMutex, PancakeType::BananaPancakes);
    manager.CreateAndRunCook(buffet, buffetMutex, PancakeType::ChocolatePancakes);
    manager.CreateAndRunCook(buffet, buffetMutex, PancakeType::BlueberryPancakes);

    std::this_thread::sleep_for(std::chrono::seconds(15));

    std::cout<< "Buffet size: " << std::endl << 
    "Banana: "<< buffet[PancakeType::BananaPancakes] << std::endl <<
    "Chocolate: "<< buffet[PancakeType::ChocolatePancakes] << std::endl <<
    "Blueberry: "<< buffet[PancakeType::BlueberryPancakes] << std::endl;

    return 0;
}
