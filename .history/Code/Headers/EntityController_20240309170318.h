#pragma once

#include <vector>

#include "Manager.h"
#include "Client.h"
#include "Cook.h"

class EntityController
{
private:
    /// @brief pointer to the manager object
    Manager* manager;

    /// @brief vector of pointers to the cook objects
    std::vector<Cook*> cooks;

    /// @brief vector of pointers to the client objects
    std::vector<Client*> clients;

public:
    /// @brief Construct a new Entity Controller object
    EntityController();

    /// @brief Destroy the Entity Controller object
    ~EntityController();

    /// @brief Create and run the manager object on new thread
    /// @param managerInitialIngredientsAmount initial amount of ingredients that manager will be adding to the fridge
    void RunManager(int managerInitialIngredientsAmount);

    /// @brief Create and run the client object on new thread
    /// @param pancakeTypeSpecialization Type of pancake that the cook specializes in (makes)
    /// @param minCookingTimeMs minimum cooking time in milliseconds
    /// @param maxCookingTimeMs maximum cooking time in milliseconds
    void AddCook(PancakeType pancakeTypeSpecialization, int minCookingTimeMs, int maxCookingTimeMs);

    /// @brief Create and run the client object on new thread
    /// @param minOrderTimeMs minimum time in milliseconds that the client will wait before going to buffet
    /// @param maxOrderTimeMs maximum time in milliseconds that the client will wait before going to buffet
    void AddClient(int minOrderTimeMs, int maxOrderTimeMs);

    /// @brief Method that stops and deletes client
    void DeleteClient();

    /// @brief Method that stops and deletes cook
    /// @param cookToDeleteSpecialization 
    void DeleteCook(PancakeType cookToDeleteSpecialization);

    int GetAmountOfClients() { return clients.size(); }
    int GetAmountOfClientsInGivenState(ClientState state);

    int GetAmountOfCooks() { return cooks.size(); }
    int GetAmountOfCooksInGivenState(CookState state);
    
    ManagerState GetManagerState() { return manager->GetState(); }
};





