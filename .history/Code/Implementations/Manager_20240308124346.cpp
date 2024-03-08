#include "../Headers/Manager.h"


//! Will not compile without it, why? - no idea
// std::condition_variable Manager::bananaPancakesLimitCondition;
// std::condition_variable Manager::blueberryPancakesLimitCondition;
// std::condition_variable Manager::chocolatePancakesLimitCondition;


Manager::Manager(int ingredientsAddAmount)
{
    Manager::ingredientsAddAmount = ingredientsAddAmount;
    this->state = ManagerState::Idle;
}

Manager::~Manager()
{

}


void Manager::Run()
{
    std::thread managerThread([this] {
        while (true)
        {
            this->state = ManagerState::AddingIngredients;

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

            this->state = ManagerState::CheckingBuffet;

            std::unique_lock<std::mutex> buffetLock(Containers::buffetMutex);
            if(Containers::buffet[PancakeType::BananaPancakes] < Containers::buffetPancakesLimits[PancakeType::BananaPancakes])
                Manager::BananaPancakesLimitCondition.notify_all();
                
            if(Containers::buffet[PancakeType::BlueberryPancakes] < Containers::buffetPancakesLimits[PancakeType::BlueberryPancakes])
                Manager::BlueberryPancakesLimitCondition.notify_all();
            
            if(Containers::buffet[PancakeType::ChocolatePancakes] < Containers::buffetPancakesLimits[PancakeType::ChocolatePancakes])
                Manager::ChocolatePancakesLimitCondition.notify_all();
            buffetLock.unlock();

            this->state = ManagerState::Resting;
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    });

    if(managerThread.joinable())
        managerThread.detach();

}