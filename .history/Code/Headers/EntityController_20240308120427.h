#pragma once

#include <vector>

#include "Manager.h"
#include "Client.h"
#include "Cook.h"

class EntityController
{
private:
    Manager manager;
    std::vector<Cook> cooks;
    std::vector<Client> clients;

public:
    EntityController(/* args */);
    ~EntityController();
};

EntityController::EntityController(/* args */)
{
}

EntityController::~EntityController()
{
}
