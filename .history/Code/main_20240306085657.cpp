#include <iostream>
#include <vector>
#include <mutex>
#include "Enums/PancakesTypes.cpp"
#include "Headers/Cook.h"


std::vector<PancakeType> buffet;
std::mutex buffetMutex;

int main(int argc, char const *argv[])
{
    Cook cook(PancakeType::BananaPancakes, 1000, 500);

    std::cout << "Hello World" << std::endl;
    return 0;
}
