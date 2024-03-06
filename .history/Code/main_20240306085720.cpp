#include <iostream>
#include <vector>
#include <mutex>
#include "Enums/PancakesTypes.cpp"
#include "Headers/Cook.h"


std::vector<PancakeType> buffet;
std::mutex buffetMutex;

int main(int argc, char const *argv[])
{
    Cook cook1(PancakeType::BananaPancakes, 1000, 5000);
    Cook cook2(PancakeType::BlueberryPancakes, 1000, 5000);
    Cook cook3(PancakeType::ChocolateChipPancakes, 1000, 5000);

    std::cout << "Hello World" << std::endl;
    return 0;
}
