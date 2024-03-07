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
    Manager manager(10,20,30);

    Cook cook1 = manager.CreateCook(PancakeType::BananaPancakes, 1000, 5000);

    cook1.Run(buffet, buffetMutex, buffetCondition);
    // cook2.Run(buffet, buffetMutex, buffetCondition);
    // cook3.Run(buffet, buffetMutex, buffetCondition);

    std::cin.get();
    return 0;
}
