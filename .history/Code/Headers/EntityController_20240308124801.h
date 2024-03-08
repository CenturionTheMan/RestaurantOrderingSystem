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
    EntityController();
    ~EntityController();

    void RunManager(int managerInitialIngredientsAmount);
    void AddCook(PancakeType pancakeTypeSpecialization, int minCookingTimeMs, int maxCookingTimeMs);
    void AddClient(int minOrderTimeMs, int maxOrderTimeMs);
};

