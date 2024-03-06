#include <iostream>
#include <vector>
#include <mutex>
#include "Enums/PancakesTypes.cpp"



std::vector<PancakeType> buffet;
std::mutex buffetMutex;

int main(int argc, char const *argv[])
{
    
    std::cout << "Hello World" << std::endl;
    return 0;
}
