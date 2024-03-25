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
        cook->Stop();
        delete cook;
    }
    for (auto client : clients)
    {
        client->Stop();
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
    Client* client = new Client(*manager, minOrderTimeMs, maxOrderTimeMs);
    clients.push_back(client);
    client->Run();
}

void EntityController::DeleteClient()
{
    if(clients.size() > 0)
    {
        Client* client = clients.back();
        client->Stop();
        clients.pop_back();
        delete client;
    }
}

void EntityController::DeleteCook(PancakeType cookToDeleteSpecialization)
{
    for (int i = 0; i < cooks.size(); i++)
    {
        if(cooks[i]->GetSpecialization() == cookToDeleteSpecialization)
        {
            Cook* cook = cooks[i];
            cook->Stop();
            cooks.erase(cooks.begin() + i);
            delete cook;
            break;
        }
    }

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
