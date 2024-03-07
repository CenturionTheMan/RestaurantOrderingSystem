#include <iostream>
#include <vector>
#include <mutex>
#include <condition_variable>
#include "Headers/Cook.h"
#include "Headers/PancakesTypes.h"

const int CookMinCookingTime = 1000;
const int CookMaxCookingTime = 5000;

std::vector<PancakeType> buffet;
std::condition_variable buffetCondition;
std::mutex buffetMutex;

int main(int argc, char const *argv[])
{
    Cook cook1(PancakeType::BananaPancakes, 1000, 5000);
    Cook cook2(PancakeType::BlueberryPancakes, 1000, 5000);
    Cook cook3(PancakeType::ChocolatePancakes, 1000, 5000);

    cook1.Run(buffet, buffetMutex, buffetCondition);
    cook2.Run(buffet, buffetMutex, buffetCondition);
    cook3.Run(buffet, buffetMutex, buffetCondition);

    std::cin.get();
    return 0;
}
