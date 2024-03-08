#pragma once

#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include "PancakesTypes.h"
#include "RestaurantContainers.h"


class Client
{
private:
    /* data */
public:
    Client(/* args */);
    ~Client();

    void Run();
};

Client::Client(/* args */)
{
}

Client::~Client()
{
}


void Client::Run()
{
    
}