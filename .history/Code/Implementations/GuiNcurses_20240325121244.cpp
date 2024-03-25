#include "../Headers/GuiNcurses.h"


#pragma region CTOR/DTOR

GuiNcurses::GuiNcurses(EntityController& entityController)
{
    GuiNcurses::entityController = &entityController;

    initscr(); // init ncurses
    cbreak(); //C^ will exit program
    noecho(); // do not print user input

    // create windows
    contentWindow  = newwin(WINDOW_HEIGHT*9/10, WINDOW_WIDTH*50/100, WINDOW_START_Y, WINDOW_START_X + WINDOW_WIDTH*25/100);
    bottomWindow = newwin(WINDOW_HEIGHT*1/10, WINDOW_WIDTH * 75/100, WINDOW_HEIGHT*9/10, WINDOW_START_X);
    leftWindow = newwin(WINDOW_HEIGHT*9/10, WINDOW_WIDTH*25/100, WINDOW_START_Y, WINDOW_START_X);
    rightWindow = newwin(WINDOW_HEIGHT, WINDOW_WIDTH*25/100, WINDOW_START_Y, WINDOW_START_X + WINDOW_WIDTH*75/100);
    refresh(); 

    // draw boxes (borders)
    box(contentWindow, 0, 0);
    box(bottomWindow, 0, 0);
    box(leftWindow, 0, 0);
    box(rightWindow, 0, 0);

    mvwprintw(contentWindow, 1, 2, "|RESTAURANT|");
    mvwprintw(leftWindow, 1, 2, "|CONTAINERS|");
    // mvwprintw(bottomWindow, 1, 2, "USER INPUT > ");
    mvwprintw(rightWindow, 1, 2, "|COMMANDS|");

    wrefresh(contentWindow);
    wrefresh(bottomWindow);
    wrefresh(leftWindow);
    wrefresh(rightWindow);

    DrawContent();
    DrawLeft();
    DrawRight();
    DrawBottom();
}

GuiNcurses::~GuiNcurses()
{
}

#pragma endregion CTOR/DTOR



#pragma region PRIVATE_METHODS

std::stringstream userInputStream;


void GuiNcurses::DrawBottom()
{
    std::string tmp = "USER INPUT > " + userInputStream.str();
    for (int i = 2; i < WINDOW_WIDTH * 75/100 - 1; i++)
    {
        mvwprintw(bottomWindow, 1, i, " ");
    }
    mvwprintw(bottomWindow, 1, 2, "%s", tmp.data());
    wrefresh(bottomWindow);
}

void GuiNcurses::DrawRight()
{
    mvwprintw(rightWindow, 4, 2, "%s", (COMMAND_ADD_CLIENT + "^X").data());
    mvwprintw(rightWindow, 5, 2, "%s", (COMMAND_DELETE_CLIENT + "^X").data());

    mvwprintw(rightWindow, 7, 2, "%s", (COMMAND_ADD_COOK_BANANA + "^X").data());
    mvwprintw(rightWindow, 8, 2, "%s", (COMMAND_ADD_COOK_CHOCOLATE + "^X").data());
    mvwprintw(rightWindow, 9, 2, "%s", (COMMAND_ADD_COOK_BLUEBERRY + "^X").data());

    mvwprintw(rightWindow, 11, 2, "%s", (COMMAND_DELETE_COOK_BANANA + "^X").data());
    mvwprintw(rightWindow, 12, 2, "%s", (COMMAND_DELETE_COOK_CHOCOLATE + "^X").data());
    mvwprintw(rightWindow, 13, 2, "%s", (COMMAND_DELETE_COOK_BLUEBERRY + "^X").data());
    
    mvwprintw(rightWindow, 15, 2, "%s", (COMMAND_SET_FRIDGE_LIMIT_BANANA + "^X").data());
    mvwprintw(rightWindow, 16, 2, "%s", (COMMAND_SET_FRIDGE_LIMIT_CHOCOLATE + "^X").data());
    mvwprintw(rightWindow, 17, 2, "%s", (COMMAND_SET_FRIDGE_LIMIT_BLUEBERRY + "^X").data());
    mvwprintw(rightWindow, 18, 2, "%s", (COMMAND_SET_FRIDGE_LIMIT_COMMONS + "^X").data());
    
    mvwprintw(rightWindow, 20, 2, "%s", (COMMAND_SET_BUFFET_LIMIT_BANANA + "^X").data());
    mvwprintw(rightWindow, 21, 2, "%s", (COMMAND_SET_BUFFET_LIMIT_CHOCOLATE + "^X").data());
    mvwprintw(rightWindow, 22, 2, "%s", (COMMAND_SET_BUFFET_LIMIT_BLUEBERRY + "^X").data());
    
    mvwprintw(rightWindow, 24, 2, "%s", (COMMAND_SET_INGREDIENTS_TO_ADD_AMOUNT + "^X").data());
    
    mvwprintw(rightWindow, 26, 2, "%s", COMMAND_EXIT.data());

    wrefresh(rightWindow);
}

void GuiNcurses::DrawContent()
{
    std::stringstream stream;

    //DRAW FRIDGE
    stream << "COOKS:" << std::setw(4) << std::right << GuiNcurses::entityController->GetAmountOfCooksInGivenState(CookState::WaitingForFridge);
    mvwvline(contentWindow, 3, contentWindow->_maxx - 7, (int)'#', 3);
    mvwvline(contentWindow, 3, contentWindow->_maxx - 16, (int)'#', 3);
    mvwprintw(contentWindow, 4, contentWindow->_maxx - 15, " FRIDGE ");
    mvwhline(contentWindow, 3, contentWindow->_maxx - 16, (int)'#', 9);
    mvwhline(contentWindow, 5, contentWindow->_maxx - 16, (int)'#', 9);
    mvwprintw(contentWindow, 6, contentWindow->_maxx - 16, "%s", stream.str().c_str());
    stream.str(std::string());

    //DRAW WALKING COOKS TO FRIDGE
    stream << "COOKS:" << std::setw(4) << std::right << GuiNcurses::entityController->GetAmountOfCooksInGivenState(CookState::GoingToFridge);
    mvwvline(contentWindow, 11, contentWindow->_maxx - 5, (int)'#', 3);
    mvwvline(contentWindow, 11, contentWindow->_maxx - 16, (int)'#', 3);
    mvwprintw(contentWindow, 12, contentWindow->_maxx - 15, " GOING TO ");
    mvwprintw(contentWindow, 13, contentWindow->_maxx - 15, "  FRIDGE  ");
    mvwhline(contentWindow, 11, contentWindow->_maxx - 16, (int)'#', 12);
    mvwhline(contentWindow, 14, contentWindow->_maxx - 16, (int)'#', 12);
    mvwprintw(contentWindow, 15, contentWindow->_maxx - 16, "%s", stream.str().c_str());
    stream.str(std::string()); 

    //DRAW OVENS
    stream << "COOKS:" << std::setw(4) << std::right << GuiNcurses::entityController->GetAmountOfCooksInGivenState(CookState::Cooking);
    mvwvline(contentWindow, 20, contentWindow->_maxx - 7, (int)'#', 3);
    mvwvline(contentWindow, 20, contentWindow->_maxx - 16, (int)'#', 3);
    mvwprintw(contentWindow, 21, contentWindow->_maxx - 15, " OVENS ");
    mvwhline(contentWindow, 20, contentWindow->_maxx - 16, (int)'#', 9);
    mvwhline(contentWindow, 22, contentWindow->_maxx - 16, (int)'#', 9);
    mvwprintw(contentWindow, 23, contentWindow->_maxx - 16, "%s", stream.str().c_str());
    stream.str(std::string());

    //DRAW WALKING COOKS TO BUFFET
    stream << "COOKS:" << std::setw(4) << std::right << GuiNcurses::entityController->GetAmountOfCooksInGivenState(CookState::CookGoingToBuffet);
    mvwvline(contentWindow, 17, 27, (int)'#', 3);
    mvwvline(contentWindow, 17, 38, (int)'#', 3);
    mvwprintw(contentWindow, 17, 28, " GOING TO ");
    mvwprintw(contentWindow, 18, 28, "  BUFFET  ");
    mvwhline(contentWindow, 16, 27, (int)'#', 12);
    mvwhline(contentWindow, 19, 27, (int)'#', 12);
    mvwprintw(contentWindow, 20, 27, "%s", stream.str().c_str());
    stream.str(std::string());

    //DRAW BUFFET
    mvwvline(contentWindow, 20, 5, (int)'#', 3);
    mvwvline(contentWindow, 20, 16, (int)'#', 3);
    mvwprintw(contentWindow, 21, 6, "  BUFFET  ");
    mvwhline(contentWindow, 20, 5, (int)'#', 11);
    mvwhline(contentWindow, 22, 5, (int)'#', 11);
    stream << "CLIENTS:" << std::setw(4) << std::right << GuiNcurses::entityController->GetAmountOfClientsInGivenState(ClientState::ClientWaitingForBuffet);
    mvwprintw(contentWindow, 23, 5, "%s", stream.str().c_str());
    stream.str(std::string());
    stream << "  COOKS:" << std::setw(4) << std::right << GuiNcurses::entityController->GetAmountOfCooksInGivenState(CookState::CookWaitingForBuffet);
    mvwprintw(contentWindow, 24, 5, "%s", stream.str().c_str());
    stream.str(std::string());

    //DRAW WALKING CLIENTS TO BUFFET
    stream << "CLIENTS:" << std::setw(4) << std::right << GuiNcurses::entityController->GetAmountOfClientsInGivenState(ClientState::ClientGoingToBuffet);
    mvwvline(contentWindow, 11, 5, (int)'#', 3);
    mvwvline(contentWindow, 11, 16, (int)'#', 3);
    mvwprintw(contentWindow, 12, 6, " GOING TO ");
    mvwprintw(contentWindow, 13, 6, "  BUFFET  ");
    mvwhline(contentWindow, 11, 5, (int)'#', 12);
    mvwhline(contentWindow, 14, 5, (int)'#', 12);
    mvwprintw(contentWindow, 15, 5, "%s", stream.str().c_str());
    stream.str(std::string());

    //DRAW CANTEEN
    stream << "CLIENTS:" << std::setw(4) << std::right << GuiNcurses::entityController->GetAmountOfClientsInGivenState(ClientState::Eating);
    mvwvline(contentWindow, 3, 5, (int)'#', 3);
    mvwvline(contentWindow, 3, 16, (int)'#', 3);
    mvwprintw(contentWindow, 4, 6, bottom" CANTEEN ");
    mvwhline(contentWindow, 3, 5, (int)'#', 11);
    mvwhline(contentWindow, 5, 5, (int)'#', 11);
    mvwprintw(contentWindow, 6, 5, "%s", stream.str().c_str());
    stream.str(std::string());

    //DRAW MANAGER
    std::string tmp = EntityStateToString(entityController->GetManagerState());
    mvwprintw(contentWindow, 8, 24, "MANAGER STATE:");
    mvwhline(contentWindow, 7, 24, (int)'#', 18);
    mvwhline(contentWindow, 10, 24, (int)'#', 18);
    mvwprintw(contentWindow, 9, 24, "%s", "                 "); //clear previous state
    mvwprintw(contentWindow, 9, 24, "%s", tmp.data());

    wrefresh(contentWindow);
}

void GuiNcurses::DrawLeft()
{
    std::stringstream stream;

    mvwprintw(leftWindow, 3, 2, "FRIDGE: ");

    stream << "-Banana:         " << std::setw(4) << std::right << Containers::fridge[PancakeIngredient::Banana] 
            << "/" 
            << Containers::fridgeIngredientLimits[PancakeIngredient::Banana];
    mvwprintw(leftWindow, 4, 2, "%s", stream.str().c_str());
    stream.str(std::string());

    stream << "-Blueberry:      " << std::setw(4) << std::right << Containers::fridge[PancakeIngredient::Blueberry] 
            << "/" 
            << Containers::fridgeIngredientLimits[PancakeIngredient::Blueberry];
    mvwprintw(leftWindow, 5, 2, "%s", stream.str().c_str());
    stream.str(std::string());

    stream << "-Chocolate:      " << std::setw(4) << std::right << Containers::fridge[PancakeIngredient::Chocolate] 
            << "/" 
            << Containers::fridgeIngredientLimits[PancakeIngredient::Chocolate];
    mvwprintw(leftWindow, 6, 2, "%s", stream.str().c_str());
    stream.str(std::string());

    stream << "-Eggs/Milk/Flour:" << std::setw(4) << std::right << Containers::fridge[PancakeIngredient::Eggs_Milk_Flour] 
            << "/" 
            << Containers::fridgeIngredientLimits[PancakeIngredient::Eggs_Milk_Flour];
    mvwprintw(leftWindow, 7, 2, "%s", stream.str().c_str());
    stream.str(std::string());


    mvwprintw(leftWindow, 9, 2, "BUFFET: ");

    stream << "  Pancakes " << std::setw(10) << std::right << Containers::buffet[PancakeType::BananaPancakes] 
            << "/" 
            << Containers::buffetPancakesLimits[PancakeType::BananaPancakes];
    mvwprintw(leftWindow, 10, 2, "-Banana ");
    mvwprintw(leftWindow, 11, 2, "%s", stream.str().c_str());
    stream.str(std::string());

    stream << "  Pancakes " << std::setw(10) << std::right << Containers::buffet[PancakeType::BlueberryPancakes] 
            << "/" 
            << Containers::buffetPancakesLimits[PancakeType::BlueberryPancakes];
    mvwprintw(leftWindow, 12, 2, "-Blueberry ");
    mvwprintw(leftWindow, 13, 2, "%s", stream.str().c_str());
    stream.str(std::string());


    stream << "  Pancakes " << std::setw(10) << std::right << Containers::buffet[PancakeType::ChocolatePancakes] 
            << "/" 
            << Containers::buffetPancakesLimits[PancakeType::ChocolatePancakes];
    mvwprintw(leftWindow, 14, 2, "-Chocolate ");
    mvwprintw(leftWindow, 15, 2, "%s", stream.str().c_str());
    stream.str(std::string());


    stream << "COOKS AMOUNT:   " << std::setw(5) << std::right << GuiNcurses::entityController->GetAmountOfCooks();
    mvwprintw(leftWindow, 18, 2, "%s", stream.str().data());
    stream.str(std::string());

    stream << "CLIENTS AMOUNT: " << std::setw(5) << std::right << GuiNcurses::entityController->GetAmountOfClients();
    mvwprintw(leftWindow, 19, 2, "%s", stream.str().data());
    stream.str(std::string());

    wrefresh(leftWindow);
}

#pragma endregion PRIVATE_METHODS


#pragma region PUBLIC_METHODS

void GuiNcurses::RunGui()
{
    bool exit = false;
    
    std::thread outputThread([this, &exit](){
        while (!exit)
        {
            this->DrawContent();
            this->DrawLeft();
            // this->DrawRight();
            this->DrawBottom();

            std::this_thread::sleep_for(std::chrono::milliseconds(34));
        }
    });

    std::thread inputThread([this, &exit](){
        while (!exit)
        {
            char tmp = getch();
            
            if(tmp == '\177') //backspace
            {
                std::string prev = this->userInputStream.str();
                if (prev.size() == 0)
                    continue;
                prev.erase(prev.end() - 1);
                this->userInputStream.str(std::string());
                this->userInputStream << prev;
                continue;
            }

            if(tmp != '\n' && this->userInputStream.str().size() < this->bottomWindow->_maxx - 17)
            {
                this->userInputStream << tmp;
                continue;
            }
            
            
            std::string input = this->userInputStream.str();
            this->userInputStream.str(std::string());

            input.erase(std::remove(input.begin(), input.end(), '\n'), input.end());
            input.erase(std::remove(input.begin(), input.end(), ' '), input.end());

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
                    this->entityController->AddClient(1000, 2000);
            }
            else if(input == COMMAND_ADD_COOK_BANANA)
            {
                for (int i = 0; i < amount; i++)
                    this->entityController->AddCook(PancakeType::BananaPancakes, 1000, 2000);
            }
            else if(input == COMMAND_ADD_COOK_CHOCOLATE)
            {
                for (int i = 0; i < amount; i++)
                    this->entityController->AddCook(PancakeType::ChocolatePancakes, 1000, 2000);
            }
            else if(input == COMMAND_ADD_COOK_BLUEBERRY)
            {
                for (int i = 0; i < amount; i++)
                    this->entityController->AddCook(PancakeType::BlueberryPancakes, 1000, 2000);
            }
            else if(input == COMMAND_DELETE_CLIENT)
            {
                for (int i = 0; i < amount; i++)
                    this->entityController->DeleteClient();
            }
            else if(input == COMMAND_DELETE_COOK_BANANA)
            {
                for (int i = 0; i < amount; i++)
                    this->entityController->DeleteCook(PancakeType::BananaPancakes);
            }
            else if(input == COMMAND_DELETE_COOK_CHOCOLATE)
            {
                for (int i = 0; i < amount; i++)
                    this->entityController->DeleteCook(PancakeType::ChocolatePancakes);
            }
            else if(input == COMMAND_DELETE_COOK_BLUEBERRY)
            {
                for (int i = 0; i < amount; i++)
                    this->entityController->DeleteCook(PancakeType::BlueberryPancakes);
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
                this->entityController->GetManager()->SetIngredientsAddAmount(amount);
            }
            else if(input == COMMAND_EXIT)
            {
                exit = true;
            }
            else
            {
               //??
            }
        }
    });


    if(outputThread.joinable())
        outputThread.join();

    if(inputThread.joinable())
        inputThread.join();

    endwin();
}
#pragma endregion PUBLIC_METHODS