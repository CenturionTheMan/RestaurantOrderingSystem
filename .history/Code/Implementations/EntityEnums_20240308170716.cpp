#include "../Headers/EntityEnums.h"

std::string ClientStateToString(ClientState state)
{
    switch (state)
    {
    case ClientState::ClientIdle:
        return "ClientIdle";
    case ClientState::ClientGoingToBuffet:
        return "ClientGoingToBuffet";
    case ClientState::NoFoodToEat:
        return "NoFoodToEat";
    case ClientState::Eating:
        return "Eating";
    default:
        return "Unknown";
    }
}

std::string ManagerStateToString(ManagerState state)
{
    switch (state)
    {
    case ManagerState::ManagerIdle:
        return "ManagerIdle";
    case ManagerState::AddingIngredients:
        return "AddingIngredients";
    case ManagerState::CheckingBuffet:
        return "CheckingBuffet";
    case ManagerState::Resting:
        return "Resting";
    default:
        return "Unknown";
    }
}

std::string CookStateToString(CookState state)
{
    switch (state)
    {
    case CookState::CookIdle:
        return "CookIdle";
    case CookState::GoingToFridge:
        return "GoingToFridge";
    case CookState::WaitingForFridge:
        return "WaitingForFridge";
    case CookState::Cooking:
        return "Cooking";
    case CookState::CookGoingToBuffet:
        return "CookGoingToBuffet";
    case CookState::WaitingForBuffet:
        return "WaitingForBuffet";
    default:
        return "Unknown";
    }
}
