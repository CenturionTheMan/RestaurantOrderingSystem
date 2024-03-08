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


std::string EntityStateToString(ClientState state);
std::string EntityStateToString(ManagerState state);
std::string EntityStateToString(CookState state);