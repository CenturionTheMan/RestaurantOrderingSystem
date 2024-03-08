#include "../Headers/Gui.h"


void Gui::RunGui(EntityController& entityController, int refreshRateInMs)
{
    std::thread guiThread([&entityController, refreshRateInMs](){
        while (true)
        {
            printf("\033c"); //! for vscode specific
            std::stringstream stream;

            stream << Gui::BREAK_LINE <<"|          RESTAURANT SUPERVISOR \n" << Gui::BREAK_LINE;
            stream << "| Manager state: " << std::setw(4) << std::right << EntityStateToString(entityController.GetManagerState()) << std::endl << Gui::BREAK_LINE;
            
            stream << "| Clients: \n" << 
            "|  - Total:            " << std::setw(4) << std::right << entityController.GetAmountOfClients() << std::endl <<
            "|  - Idle:             " << std::setw(4) << std::right << entityController.GetAmountOfClientsInGivenState(ClientState::ClientIdle) << std::endl <<
            "|  - GoingToBuffet:    " << std::setw(4) << std::right << entityController.GetAmountOfClientsInGivenState(ClientState::ClientGoingToBuffet) << std::endl <<
            "|  - Eating:           " << std::setw(4) << std::right << entityController.GetAmountOfClientsInGivenState(ClientState::Eating) << std::endl <<
            "|  - NoFoodToEat:      " << std::setw(4) << std::right << entityController.GetAmountOfClientsInGivenState(ClientState::NoFoodToEat) << std::endl << Gui::BREAK_LINE;

            stream << "| Cooks: \n" <<
            "|  - Total:            " << std::setw(4) << std::right << entityController.GetAmountOfCooks() << std::endl <<
            "|  - Idle:             " << std::setw(4) << std::right << entityController.GetAmountOfCooksInGivenState(CookState::CookIdle) << std::endl <<
            "|  - GoingToFridge:    " << std::setw(4) << std::right << entityController.GetAmountOfCooksInGivenState(CookState::GoingToFridge) << std::endl <<
            "|  - WaitingForFridge: " << std::setw(4) << std::right << entityController.GetAmountOfCooksInGivenState(CookState::WaitingForFridge) << std::endl <<
            "|  - Cooking:          " << std::setw(4) << std::right << entityController.GetAmountOfCooksInGivenState(CookState::Cooking) << std::endl <<
            "|  - GoingToBuffet:    " << std::setw(4) << std::right << entityController.GetAmountOfCooksInGivenState(CookState::CookGoingToBuffet) << std::endl <<
            "|  - WaitingForBuffet: " << std::setw(4) << std::right << entityController.GetAmountOfCooksInGivenState(CookState::WaitingForBuffet) << std::endl << Gui::BREAK_LINE;

            stream << "| Buffet: \n" <<
            "|  - BananaPancakes:   " << std::setw(4) << std::right << entityController.GetAmountOfPancakesInBuffet(PancakeType::BananaPancakes) << std::endl <<
            "|  - BlueberryPancakes: " << std::setw(4) << std::right << entityController.GetAmountOfPancakesInBuffet(PancakeType::BlueberryPancakes) << std::endl <<
            "|  - ChocolatePancakes: " << std::setw(4) << std::right << entityController.GetAmountOfPancakesInBuffet(PancakeType::ChocolatePancakes) << std::endl << Gui::BREAK_LINE;
            

            std::cout << stream.str();
            std::this_thread::sleep_for(std::chrono::milliseconds(refreshRateInMs));
        }
    });

    if(guiThread.joinable())
            guiThread.detach();
}