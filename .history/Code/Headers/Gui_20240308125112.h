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
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        system("clear");
        std::cout << "Manager state: " << entityController.GetManagerState() << std::endl;
        std::cout << "Clients: " << std::endl;
        std::cout << "Idle: " << entityController.GetAmountOfClientsInGivenState(ClientState::Idle) << std::endl;
        std::cout << "Going to buffet: " << entityController.GetAmountOfClientsInGivenState(ClientState::GoingToBuffet) << std::endl;
        std::cout << "No food to eat: " << entityController.GetAmountOfClientsInGivenState(ClientState::NoFoodToEat) << std::endl;
        std::cout << "Eating: " << entityController.GetAmountOfClientsInGivenState(ClientState::Eating) << std::endl;
        std::cout << "Cooks: " << std::endl;
        std::cout << "Idle: " << entityController.GetAmountOfCooksInGivenState(CookState::Idle) << std::endl;
        std::cout << "Cooking: " << entityController.GetAmountOfCooksInGivenState(CookState::Cooking) << std::endl;
        std::cout << "Resting: " << entityController.GetAmountOfCooksInGivenState(CookState::Resting) << std::endl;
    }
}