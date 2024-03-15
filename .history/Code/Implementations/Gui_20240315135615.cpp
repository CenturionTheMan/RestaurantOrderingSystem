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
    "|  - WaitingForBuffet: " << std::setw(4) << std::right << entityController.GetAmountOfClientsInGivenState(ClientState::ClientWaitingForBuffet) << std::endl <<
    "|  - Eating:           " << std::setw(4) << std::right << entityController.GetAmountOfClientsInGivenState(ClientState::Eating) << std::endl << Gui::BREAK_LINE;

    stream << "| Cooks: \n" <<
    "|  - Total:            " << std::setw(4) << std::right << entityController.GetAmountOfCooks() << std::endl <<
    "|  - Idle:             " << std::setw(4) << std::right << entityController.GetAmountOfCooksInGivenState(CookState::CookIdle) << std::endl <<
    "|  - GoingToFridge:    " << std::setw(4) << std::right << entityController.GetAmountOfCooksInGivenState(CookState::GoingToFridge) << std::endl <<
    "|  - WaitingForFridge: " << std::setw(4) << std::right << entityController.GetAmountOfCooksInGivenState(CookState::WaitingForFridge) << std::endl <<
    "|  - Cooking:          " << std::setw(4) << std::right << entityController.GetAmountOfCooksInGivenState(CookState::Cooking) << std::endl <<
    "|  - GoingToBuffet:    " << std::setw(4) << std::right << entityController.GetAmountOfCooksInGivenState(CookState::CookGoingToBuffet) << std::endl <<
    "|  - WaitingForBuffet: " << std::setw(4) << std::right << entityController.GetAmountOfCooksInGivenState(CookState::CookWaitingForBuffet) << std::endl << Gui::BREAK_LINE;

    std::cout << stream.str();
}

void Gui::ClearScreen()
{
     system("cls"); 
    //printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\033c"); //! for vscode specific
}

void Gui::PrintUserInput()
{
    std::cout << "| Commands: " << std::endl << "| " << Gui::COMMAND_EXIT << " | " << Gui::COMMAND_ADD_CLIENT + "^X" << " | " << Gui::COMMAND_ADD_COOK_BANANA + "^X" << " | " 
    << Gui::COMMAND_ADD_COOK_CHOCOLATE + "^X" << " | " 
    << Gui::COMMAND_ADD_COOK_BLUEBERRY + "^X" << " | " << Gui::COMMAND_DELETE_CLIENT + "^X" << " | " << Gui::COMMAND_DELETE_COOK_BANANA + "^X" << " | " 
    << Gui::COMMAND_DELETE_COOK_CHOCOLATE + "^X" << " | " << Gui::COMMAND_DELETE_COOK_BLUEBERRY + "^X" << " |\n| " << Gui::COMMAND_SET_BUFFET_LIMIT_BANANA + "^X" << " | "
    << Gui::COMMAND_SET_BUFFET_LIMIT_CHOCOLATE + "^X" << " | " << Gui::COMMAND_SET_BUFFET_LIMIT_BLUEBERRY + "^X" << " | " << Gui::COMMAND_SET_FRIDGE_LIMIT_BANANA + "^X" << " | "
    << Gui::COMMAND_SET_FRIDGE_LIMIT_BLUEBERRY + "^X" << " | " << Gui::COMMAND_SET_FRIDGE_LIMIT_CHOCOLATE + "^X" << " | " << Gui::COMMAND_SET_FRIDGE_LIMIT_COMMONS + "^X" << " |\n| "
    << Gui::COMMAND_SET_INGREDIENTS_TO_ADD_AMOUNT + "^X" << " | " << std::endl
    << std::endl << BREAK_LINE;
    std::cout << "| Last user input: " << Gui::UserInput << std::endl;
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

        input.erase(std::remove(input.begin(), input.end(), '\n'), input.end());
        input.erase(std::remove(input.begin(), input.end(), ' '), input.end());

        Gui::UserInput = input;

        int amount = 1;
        if (input.find("^") != std::string::npos)
        {
            std::string amountInString = input.substr(input.find("^") + 1); 
            amount = atoi( amountInString.c_str() );
            input = input.substr(0, input.find("^"));
        }
        

        if(input == COMMAND_ADD_CLIENT)
        {
            for (int i = 0; i < amount; i++)
                entityController.AddClient(1000, 2000);
        }
        else if(input == COMMAND_ADD_COOK_BANANA)
        {
            for (int i = 0; i < amount; i++)
                entityController.AddCook(PancakeType::BananaPancakes, 1000, 2000);
        }
        else if(input == COMMAND_ADD_COOK_CHOCOLATE)
        {
            for (int i = 0; i < amount; i++)
                entityController.AddCook(PancakeType::ChocolatePancakes, 1000, 2000);
        }
        else if(input == COMMAND_ADD_COOK_BLUEBERRY)
        {
            for (int i = 0; i < amount; i++)
                entityController.AddCook(PancakeType::BlueberryPancakes, 1000, 2000);
        }
        else if(input == COMMAND_DELETE_CLIENT)
        {
            for (int i = 0; i < amount; i++)
                entityController.DeleteClient();
        }
        else if(input == COMMAND_DELETE_COOK_BANANA)
        {
            for (int i = 0; i < amount; i++)
                entityController.DeleteCook(PancakeType::BananaPancakes);
        }
        else if(input == COMMAND_DELETE_COOK_CHOCOLATE)
        {
            for (int i = 0; i < amount; i++)
                entityController.DeleteCook(PancakeType::ChocolatePancakes);
        }
        else if(input == COMMAND_DELETE_COOK_BLUEBERRY)
        {
            for (int i = 0; i < amount; i++)
                entityController.DeleteCook(PancakeType::BlueberryPancakes);
        }
        else if(input == COMMAND_SET_BUFFET_LIMIT_BANANA)
        {
            Containers::buffetPancakesLimits[PancakeType::BananaPancakes] = amount;
        }
        else if(input == COMMAND_SET_BUFFET_LIMIT_CHOCOLATE)
        {
            Containers::buffetPancakesLimits[PancakeType::ChocolatePancakes] = amount;
        }
        else if(input == COMMAND_SET_BUFFET_LIMIT_BLUEBERRY)
        {
            Containers::buffetPancakesLimits[PancakeType::BlueberryPancakes] = amount;
        }
        else if(input == COMMAND_SET_FRIDGE_LIMIT_BANANA)
        {
            Containers::fridgeIngredientLimits[PancakeIngredient::Banana] = amount;
        }
        else if(input == COMMAND_SET_FRIDGE_LIMIT_BLUEBERRY)
        {
            Containers::fridgeIngredientLimits[PancakeIngredient::Blueberry] = amount;
        }
        else if(input == COMMAND_SET_FRIDGE_LIMIT_CHOCOLATE)
        {
            Containers::fridgeIngredientLimits[PancakeIngredient::Chocolate] = amount;
        }
        else if(input == COMMAND_SET_FRIDGE_LIMIT_COMMONS)
        {
            Containers::fridgeIngredientLimits[PancakeIngredient::Eggs_Milk_Flour] = amount;
        }
        else if(input == COMMAND_SET_INGREDIENTS_TO_ADD_AMOUNT)
        {
            entityController.GetManager()->SetIngredientsAddAmount(amount);
        }
        else if(input == COMMAND_EXIT)
        {
            Gui::UserInput = "exit";
        }
        else
        {
            Gui::UserInput = "Invalid command";
        }

    }
}
