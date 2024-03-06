#include <iostream>
#include <vector>
#include <mutex>
#include "Headers/PancakesTypes.h"
#include "Headers/Cook.h"


std::vector<PancakeType> buffet;
std::mutex buffetMutex;

int main(int argc, char const *argv[])
{
    Cook cook1(PancakeType::BananaPancakes, 1000, 5000);
    Cook cook2(PancakeType::BlueberryPancakes, 1000, 5000);
    Cook cook3(PancakeType::ChocolateChipPancakes, 1000, 5000);

    auto t1 = cook1.Run(buffet, buffetMutex);
    auto t2 = cook2.Run(buffet, buffetMutex);
    auto t3 = cook3.Run(buffet, buffetMutex);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
