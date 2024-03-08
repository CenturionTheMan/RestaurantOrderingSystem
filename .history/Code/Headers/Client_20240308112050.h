#pragma once

#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include "PancakesTypes.h"
#include "RestaurantContainers.h"
#include "RandomGenerator.h"

class Client
{
private:
    RandomGenerator randomGenerator;
    int maxOrderTimeMs, minOrderTimeMs;

public:
    Client(int minOrderTimeMs, int maxOrderTimeMs);
    ~Client();

    void Run();
};

