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

Client::Client(int minOrderTimeMs, int maxOrderTimeMs)
{
    this->minOrderTimeMs = minOrderTimeMs;
    this->maxOrderTimeMs = maxOrderTimeMs;
    randomGenerator = RandomGenerator();
}

Client::~Client()
{
}


void Client::Run()
{   
    std::thread clientThread([this](){
       
        while (true)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(randomGenerator.GetRandomNumber(minOrderTimeMs, maxOrderTimeMs)));
            PancakeType pancakeType = static_cast<PancakeType>(randomGenerator.GetRandomNumber(0, 2));

            std::lock_guard<std::mutex> lock(Containers::buffetMutex);
            Containers::TakePancakeFromBuffet(pancakeType);
            lock.unlock();
        }
    });
}