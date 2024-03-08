#include "../Headers/Gui.h"


void Gui::RunGui(EntityController& entityController)
{
    std::thread guiThread([&entityController](){
        while (true)
        {
            std::cout << "Manager state: " << entityController.GetManagerState() << Gui::BREAK_LINE;
            std::cout << "Amount of cooks in idle state: " << entityController.GetAmountOfCooksInGivenState(CookState::CookIdle) << std::endl;
            std::cout << "Amount of cooks in cooking state: " << entityController.GetAmountOfCooksInGivenState(CookState::Cooking) << std::endl;
            std::cout << "Amount of clients in idle state: " << entityController.GetAmountOfClientsInGivenState(ClientState::ClientIdle) << std::endl;
            std::cout << "Amount of clients in going to buffet state: " << entityController.GetAmountOfClientsInGivenState(ClientState::ClientGoingToBuffet) << std::endl;
            std::cout << "Amount of clients in eating state: " << entityController.GetAmountOfClientsInGivenState(ClientState::Eating) << std::endl;
            std::cout << "Amount of clients in no food to eat state: " << entityController.GetAmountOfClientsInGivenState(ClientState::NoFoodToEat) << std::endl;
        }
    });
}