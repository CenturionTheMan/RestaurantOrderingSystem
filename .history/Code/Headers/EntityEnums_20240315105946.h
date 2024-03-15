#pragma once

#include <string>

enum ClientState
{
    ClientIdle,
    ClientGoingToBuffet,
    ClientWaitingForBuffet,
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
    CookWaitingForBuffet,
};

/// @brief Converts the given state to string
/// @param state state to convert
/// @return string
std::string EntityStateToString(ClientState state);

/// @brief Converts the given state to string
/// @param state state to convert
/// @return string
std::string EntityStateToString(ManagerState state);

/// @brief Converts the given state to string
/// @param state state to convert
/// @return string
std::string EntityStateToString(CookState state);