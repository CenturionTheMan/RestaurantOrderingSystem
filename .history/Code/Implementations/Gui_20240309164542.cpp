#include "../Headers/Gui.h"


std::string Gui::UserInput = "";


void Gui::PrintRestaurant(EntityController& entityController)
{
    std::stringstream stream;

    // stream << Gui::BREAK_LINE <<"|          RESTAURANT SUPERVISOR \n" << Gui::BREAK_LINE;
    stream << Gui::BREAK_LINE;
    stream << "| Fridge: \n" <<
    "|  - Banana:           " << std::setw(4) << std::right << Containers::fridge[PancakeIngredient::Banana] << std::endl <<
    "|  - Blueberry:        " << std::setw(4) << std::right << Containers::fridge[PancakeIngredient::Blueberry] << std::endl <<
    "|  - Chocolate:        " << std::setw(4) << std::right << Containers::fridge[PancakeIngredient::Chocolate] << std::endl <<
    "|  - Eggs_Milk_Flour:  " << std::setw(4) << std::right << Containers::fridge[PancakeIngredient::Eggs_Milk_Flour] << std::endl << Gui::BREAK_LINE;

    stream << "| Buffet: \n" <<
    "|  - BananaPancakes:    " << std::setw(4) << std::right << Containers::buffet[PancakeType::BananaPancakes] << std::endl <<
    "|  - BlueberryPancakes: " << std::setw(4) << std::right << Containers::buffet[PancakeType::BlueberryPancakes] << std::endl <<
    "|  - ChocolatePancakes: " << std::setw(4) << std::right << Containers::buffet[PancakeType::ChocolatePancakes] << std::endl << Gui::BREAK_LINE;

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

    std::cout << stream.str();
}

void Gui::ClearScreen()
{
    // system("cls"); 
    printf("\033c"); //! for vscode specific
    // printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

void Gui::PrintUserInput()
{
    std::cout   << "COMMANDS: " << Gui::CommandExit << " | " << Gui::CommandAddCookBanana << " | " << Gui::CommandAddCookChocolate << " | " << Gui::CommandAddCookBlueberry 
                << " | " << Gui::CommandAddClient << " | " << Gui::CommandDeleteClient << " | " << Gui::CommandDeleteCookBanana << " | " << Gui::CommandDeleteCookChocolate 
                << " | " << Gui::CommandDeleteCookBlueberry << std::endl << Gui::BREAK_LINE;
    std::cout << "Last user input: " << Gui::UserInput << std::endl;
}


void Gui::RunGuiOutput(EntityController& entityController, int refreshRateInMs)
{
    std::thread guiThread([&entityController, refreshRateInMs](){
        while (true)
        {
            Gui::ClearScreen();
            Gui::PrintRestaurant(entityController);
            Gui::PrintUserInput();
            std::this_thread::sleep_for(std::chrono::milliseconds(refreshRateInMs));
        }
    });


    if(guiThread.joinable())
        guiThread.detach();
}


void Gui::RunGuiInput(EntityController& entityController)
{
    while (Gui::UserInput != "exit")
    {
        std::string input;
        std::getline(std::cin, input);
        
        Gui::UserInput = input;

        input.erase(std::remove(input.begin(), input.end(), '\n'), input.end());
        input.erase(std::remove(input.begin(), input.end(), ' '), input.end());


        if(input == CommandAddCookBanana)
        {
            entityController.AddCook(PancakeType::BananaPancakes, 1000, 2000);
        }
        else if(input == CommandAddCookChocolate)
        {
            entityController.AddCook(PancakeType::ChocolatePancakes, 1000, 2000);
        }
        else if(input == CommandAddCookBlueberry)
        {
            entityController.AddCook(PancakeType::BlueberryPancakes, 1000, 2000);
        }
        else if(input == CommandAddClient)
        {
            entityController.AddClient(1000, 2000);
        }
        else if (input == CommandDeleteClient)
        {
            entityController.DeleteClient(); //!! will crash
        }
        else if (input == CommandDeleteCookBanana)
        {
            entityController.DeleteCook(PancakeType::BananaPancakes);
        }
        else if (input == CommandDeleteCookChocolate)
        {
            entityController.DeleteCook(PancakeType::ChocolatePancakes);
        }
        else if (input == CommandDeleteCookBlueberry)
        {
            entityController.DeleteCook(PancakeType::BlueberryPancakes);
        }
    }
}
