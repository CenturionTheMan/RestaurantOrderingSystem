#pragma once

#include <vector>
#include "Cook.h"

class Manager
{
private:
    std::vector<Cook> BananaPancakesCooks;
    std::vector<Cook> BlueberryPancakesCooks;
    std::vector<Cook> ChocolatePancakesCooks;

    int desiredBananaPancakes, desiredBlueberryPancakes, desiredChocolatePancakes;

public:
    Manager(int desiredBananaPancakes, int desiredBlueberryPancakes, int desiredChocolatePancakes);
    ~Manager();
};

Manager::Manager(int desiredBananaPancakes, int desiredBlueberryPancakes, int desiredChocolatePancakes)
{
    Manager::desiredBananaPancakes = desiredBananaPancakes;
    Manager::desiredBlueberryPancakes = desiredBlueberryPancakes;
    Manager::desiredChocolatePancakes = desiredChocolatePancakes;
}

Manager::~Manager()
{
}