#pragma once

#include <thread>
#include <iostream>

#include "EntityController.h"


namespace Gui
{
    void RunGui(EntityController& entityController);


} // namespace Gui


void Gui::RunGui(EntityController& entityController)
{
    std::thread guiThread([entityController](){
        while (true)
        {
            std::cout << "Manager state: " << entityController.GetManagerState() << std::endl;
            std::cout << "Amount of cooks in idle state: " << entityController.GetAmountOfCooksInGivenState(CookState::Idle) << std::endl;
            std::cout << "Amount of cooks in cooking state: " << entityController.GetAmountOfCooksInGivenState(CookState::Cooking) << std::endl;
            std::cout << "Amount of clients in idle state: " << entityController.GetAmountOfClientsInGivenState(ClientState::Idle) << std::endl;
            std::cout << "Amount of clients in going to buffet state: " << entityController.GetAmountOfClientsInGivenState(ClientState::GoingToBuffet) << std::endl;
            std::cout << "Amount of clients in eating state: " << entityController.GetAmountOfClientsInGivenState(ClientState::Eating) << std::endl;
            std::cout << "Amount of clients in no food to eat state: " << entityController.GetAmountOfClientsInGivenState(ClientState::NoFoodToEat) << std::endl;
            std::cout << "Amount of clients in waiting for food state: " << entityController.GetAmountOfClientsInGivenState(ClientState::WaitingForFood) << std::endl;
            std::cout << "Amount of clients in leaving state: " << entityController.GetAmountOfClientsInGivenState(ClientState::Leaving) << std::endl;
            std::cout << "Amount of clients in leaving state: " << entityController.GetAmountOfClientsInGivenState(ClientState::Leaving) << std::endl;
            std::cout << "Amount of clients in leaving state: " << entityController.GetAmountOfClientsInGivenState(ClientState::Leaving) << std::endl;
            std::cout << "Amount of clients in leaving state: " << entityController.GetAmountOfClientsInGivenState(ClientState::Leaving) << std::endl;
            std::cout << "Amount of clients in leaving state: " << entityController.GetAmountOfClientsInGivenState(ClientState::Leaving) << std::endl;
            std::cout << "Amount of clients in leaving state: " << entityController.GetAmountOfClientsInGivenState(ClientState::Leaving) << std::endl;
        }
    });
}