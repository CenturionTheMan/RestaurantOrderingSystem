#include <iostream>
#include <vector>
#include <mutex>
#include <condition_variable>
#include "Headers/Cook.h"
#include "Headers/PancakesTypes.h"
#include "Headers/Manager.h"


std::vector<PancakeType> buffet;
std::condition_variable buffetCondition;
std::mutex buffetMutex;


int main(int argc, char const *argv[])
{
    Manager manager(10, 20, 30);
    manager.CreateAndRunCook(buffet, buffetMutex, buffetCondition, PancakeType::BananaPancakes);
    manager.CreateAndRunCook(buffet, buffetMutex, buffetCondition, PancakeType::ChocolatePancakes);
    manager.CreateAndRunCook(buffet, buffetMutex, buffetCondition, PancakeType::BlueberryPancakes);

    // cook2.Run(buffet, buffetMutex, buffetCondition);
    // cook3.Run(buffet, buffetMutex, buffetCondition);

    std::cin.get();

    std::this_thread::sleep_for(std::chrono::seconds(4));
    return 0;
}
