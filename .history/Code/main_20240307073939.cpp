#include <iostream>
#include <vector>
#include <mutex>
#include <condition_variable>
#include "Headers/Cook.h"
#include "Headers/PancakesTypes.h"
#include "Headers/Manager.h"


std::map<PancakeType, int> buffet = {
    {PancakeType::BananaPancakes, 0},
    {PancakeType::BlueberryPancakes, 0},
    {PancakeType::ChocolatePancakes, 0}
};
std::mutex buffetMutex;


int main(int argc, char const *argv[])
{
    Manager manager(10, 20, 30);

    std::this_thread::sleep_for(std::chrono::seconds(1));


    manager.CreateAndRunCook(buffet, buffetMutex, PancakeType::BananaPancakes);
    manager.CreateAndRunCook(buffet, buffetMutex, PancakeType::ChocolatePancakes);
    manager.CreateAndRunCook(buffet, buffetMutex, PancakeType::BlueberryPancakes);



    std::this_thread::sleep_for(std::chrono::seconds(10));

    std::cout<< "Buffet size: " << buffet.size() << std::endl;

    return 0;
}
