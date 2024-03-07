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
    Manager manager();
    manager.CreateAndRunCook(buffet, buffetMutex, buffetCondition, PancakeType::BananaPancakes);
    // cook2.Run(buffet, buffetMutex, buffetCondition);
    // cook3.Run(buffet, buffetMutex, buffetCondition);

    std::cin.get();
    return 0;
}
