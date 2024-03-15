#include "../Headers/Manager.h"



Manager::Manager(int ingredientsAddAmount)
{
    Manager::ingredientsAddAmount = ingredientsAddAmount;
    this->state = ManagerState::ManagerIdle;
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
            Containers::AddIngredientsToFridge(PancakeIngredient::Banana, ingredientsAddAmount);
            Containers::AddIngredientsToFridge(PancakeIngredient::Chocolate, ingredientsAddAmount);
            Containers::AddIngredientsToFridge(PancakeIngredient::Blueberry, ingredientsAddAmount);
            Containers::AddIngredientsToFridge(PancakeIngredient::Eggs_Milk_Flour, ingredientsAddAmount*3);
            fridgeLock.unlock();
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));

            this->state = ManagerState::CheckingBuffet;
            std::unique_lock<std::mutex> buffetLock(Containers::buffetMutex);
            if(Containers::buffet[PancakeType::BananaPancakes] < Containers::buffetPancakesLimits[PancakeType::BananaPancakes])
                Manager::CooksBananaPancakesLimitCondition.notify_all();
                
            if(Containers::buffet[PancakeType::BlueberryPancakes] < Containers::buffetPancakesLimits[PancakeType::BlueberryPancakes])
                Manager::CooksBlueberryPancakesLimitCondition.notify_all();
            
            if(Containers::buffet[PancakeType::ChocolatePancakes] < Containers::buffetPancakesLimits[PancakeType::ChocolatePancakes])
                Manager::CooksChocolatePancakesLimitCondition.notify_all();

            buffetLock.unlock();

            if(Containers::buffet[PancakeType::BananaPancakes] > 0 ||
                Containers::buffet[PancakeType::BlueberryPancakes] > 0 ||
                Containers::buffet[PancakeType::ChocolatePancakes] > 0)
                Manager::ClientsBuffetCondition.notify_all();

            std::this_thread::sleep_for(std::chrono::milliseconds(1000));

            this->state = ManagerState::Resting;
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    });

    if(managerThread.joinable())
        managerThread.detach();

}