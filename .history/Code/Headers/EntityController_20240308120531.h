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
};

EntityController::EntityController()
{
    manager = new Manager(10);
}

EntityController::~EntityController()
{
}
