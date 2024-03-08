#include "../Headers/Manager.h"


//! Will not compile without it, why? - no idea
std::condition_variable Manager::bananaPancakesLimitCondition;
std::condition_variable Manager::blueberryPancakesLimitCondition;
std::condition_variable Manager::chocolatePancakesLimitCondition;
std::condition_variable Manager::fridgeConditionVariable;


Manager::Manager()
{
}

Manager::~Manager()
{
    while (!Manager::bananaCooks.empty())
    {
        Cook* cook = Manager::bananaCooks.back();
        Manager::bananaCooks.pop_back();
        delete cook;
    }

    while (!Manager::blueberryCooks.empty())
    {
        Cook* cook = Manager::blueberryCooks.back();
        Manager::blueberryCooks.pop_back();
        delete cook;
    }

    while (!Manager::chocolateCooks.empty())
    {
        Cook* cook = Manager::chocolateCooks.back();
        Manager::chocolateCooks.pop_back();
        delete cook;
    }
}


void Manager::CreateAndRunCook(PancakeType cookSpecialization)
{
    Cook* newCook = new Cook(cookSpecialization, 1000, 3000);

    switch (cookSpecialization)
    {
        case PancakeType::BananaPancakes:
            newCook->Run(Manager::bananaPancakesLimitCondition);
            bananaCooks.push_back(newCook);
            break;
        case PancakeType::BlueberryPancakes:
            newCook->Run(Manager::blueberryPancakesLimitCondition);
            blueberryCooks.push_back(newCook);
            break;
        case PancakeType::ChocolatePancakes:
            newCook->Run(Manager::chocolatePancakesLimitCondition);
            chocolateCooks.push_back(newCook);
            break;
    }

}

void Manager::RunManager()
{
    std::thread managerThread([this] {
        while (true)
        {
            std::cout << "Manager: ADDING INGREDIENTS TO FRIDGE" << std::endl;

            std::unique_lock<std::mutex> fridgeLock(Containers::fridgeMutex);
            if(Containers::fridge[PancakeIngredient::Banana] < Containers::fridgeIngredientLimits[PancakeIngredient::Banana] - ingredientsAddAmount)
                Containers::AddIngredientsToFridge(PancakeIngredient::Banana, ingredientsAddAmount);
                
            if(Containers::fridge[PancakeIngredient::Chocolate] < Containers::fridgeIngredientLimits[PancakeIngredient::Chocolate] - ingredientsAddAmount)
                Containers::AddIngredientsToFridge(PancakeIngredient::Chocolate, ingredientsAddAmount);

            if(Containers::fridge[PancakeIngredient::Blueberry] < Containers::fridgeIngredientLimits[PancakeIngredient::Blueberry] - ingredientsAddAmount)
                Containers::AddIngredientsToFridge(PancakeIngredient::Blueberry, ingredientsAddAmount);

            if(Containers::fridge[PancakeIngredient::Eggs_Milk_Flour] < Containers::fridgeIngredientLimits[PancakeIngredient::Eggs_Milk_Flour] - ingredientsAddAmount)
                Containers::AddIngredientsToFridge(PancakeIngredient::Eggs_Milk_Flour, ingredientsAddAmount);

            fridgeLock.unlock();

            
            // std::cout << "Manager: CHECKING BUFFET" << std::endl;
            // std::unique_lock<std::mutex> buffetLock(Containers::buffetMutex);
            // if(Containers::buffet[PancakeType::BananaPancakes] < Containers::buffetPancakesLimits[PancakeType::BananaPancakes])
            //     Manager::bananaPancakesLimitCondition.notify_all();
                
            // if(Containers::buffet[PancakeType::BlueberryPancakes] < Containers::buffetPancakesLimits[PancakeType::BlueberryPancakes])
            //     Manager::blueberryPancakesLimitCondition.notify_all();
            
            // if(Containers::buffet[PancakeType::ChocolatePancakes] < Containers::buffetPancakesLimits[PancakeType::ChocolatePancakes])
            //     Manager::chocolatePancakesLimitCondition.notify_all();
            // buffetLock.unlock();

            std::cout << "Manager: WAITING" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    });

    if(managerThread.joinable())
        managerThread.detach();

}