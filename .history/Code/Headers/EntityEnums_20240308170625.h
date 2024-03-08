#pragma once

#include <string>

enum ClientState
{
    ClientIdle,
    ClientGoingToBuffet,
    NoFoodToEat,
    Eating,
};


enum ManagerState
{
    ManagerIdle,
    AddingIngredients,
    CheckingBuffet,
    Resting,
};

enum CookState
{
    CookIdle,
    GoingToFridge,
    WaitingForFridge,
    Cooking,
    CookGoingToBuffet,
    WaitingForBuffet,
};


std::string ClientStateToString(ClientState state);
std::string ManagerStateToString(ManagerState state);
std::string CookStateToString(CookState state);