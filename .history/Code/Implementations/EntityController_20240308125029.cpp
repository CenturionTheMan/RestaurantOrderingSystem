#include "../Headers/EntityController.h"

EntityController::EntityController()
{
    manager = NULL;
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

void EntityController::RunManager(int managerInitialIngredientsAmount)
{
    manager = new Manager(managerInitialIngredientsAmount);
    manager->Run();
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

int EntityController::GetAmountOfClientsInGivenState(ClientState state)
{
    int amount = 0;
    for (auto client : clients)
    {
        if(client->GetState() == state)
            amount++;
    }
    return amount;
}

int EntityController::GetAmountOfCooksInGivenState(CookState state)
{
    int amount = 0;
    for (auto cook : cooks)
    {
        if(cook->GetState() == state)
            amount++;
    }
    return amount;
}
