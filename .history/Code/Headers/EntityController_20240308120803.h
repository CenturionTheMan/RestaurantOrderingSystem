#pragma once

#include <vector>

#include "Manager.h"
#include "Client.h"
#include "Cook.h"

class EntityController
{
private:
    Manager* manager;
    std::vector<Cook*> cooks;
    std::vector<Client*> clients;

public:
    EntityController(int managerInitialIngredientsAmount);
    ~EntityController();


    void AddCook(PancakeType pancakeTypeSpecialization, int minCookingTimeMs, int maxCookingTimeMs);
    void AddClient(int minOrderTimeMs, int maxOrderTimeMs);
};

EntityController::EntityController(int managerInitialIngredientsAmount)
{
    manager = new Manager(managerInitialIngredientsAmount);
}

EntityController::~EntityController()
{
    delete manager;
    for (auto cook : cooks)
    {
        delete cook;
    }
    for (auto client : clients)
    {
        delete client;
    }
}

void EntityController::AddCook(PancakeType pancakeTypeSpecialization, int minCookingTimeMs, int maxCookingTimeMs)
{
    Cook* cook = new Cook(*manager, pancakeTypeSpecialization, minCookingTimeMs, maxCookingTimeMs);
    cooks.push_back(cook);
    cook->Run();
}

void EntityController::AddClient(int minOrderTimeMs, int maxOrderTimeMs)
{
    Client* client = new Client(minOrderTimeMs, maxOrderTimeMs);
    clients.push_back(client);
    client->Run();
}