#pragma once

#include <vector>
#include "Cook.h"

class Manager
{
private:
    std::vector<Cook> BananaPancakesCooks;
    std::vector<Cook> BlueberryPancakesCooks;
    std::vector<Cook> ChocolatePancakesCooks;

public:
    Manager(/* args */);
    ~Manager();
};

Manager::Manager(/* args */)
{
}

Manager::~Manager()
{
}
