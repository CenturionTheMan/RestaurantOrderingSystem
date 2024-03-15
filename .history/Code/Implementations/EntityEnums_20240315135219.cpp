#include "../Headers/EntityEnums.h"

std::string EntityStateToString(ClientState state)
{
    switch (state)
    {
    case ClientState::ClientIdle:
        return "ClientIdle";
    case ClientState::ClientGoingToBuffet:
        return "ClientGoingToBuffet";
    case ClientState::Eating:
        return "Eating";
    case ClientState::ClientWaitingForBuffet:
        return "WaitingForBuffet";
    default:
        return "Unknown";
    }
}

std::string EntityStateToString(ManagerState state)
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

std::string EntityStateToString(CookState state)
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
    case CookState::CookWaitingForBuffet:
        return "WaitingForBuffet";
    default:
        return "Unknown";
    }
}
