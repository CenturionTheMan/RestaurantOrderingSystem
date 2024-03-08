#pragma once


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