#include "../Headers/Cook.h"


Cook::Cook(Manager& manager, PancakeType pancakeTypeSpecialization, int minCookingTimeMs, int maxCookingTimeMs)
{
    this->state = CookState::Idle;

    Cook::randomGenerator = RandomGenerator();
    switch (pancakeTypeSpecialization)
    {
        case PancakeType::BananaPancakes:
            Cook::conditionVariable = &manager.BananaPancakesLimitCondition;
            break;
        case PancakeType::BlueberryPancakes:
            Cook::conditionVariable = &manager.BlueberryPancakesLimitCondition;
            break;
        case PancakeType::ChocolatePancakes:
            Cook::conditionVariable = &manager.ChocolatePancakesLimitCondition;
            break;
        default:
        throw std::invalid_argument("Invalid pancake type specialization");
            break;
    }
    
    Cook::specializedInPancakeType = pancakeTypeSpecialization;
    Cook::maxCookingTimeMs = maxCookingTimeMs;
    Cook::minCookingTimeMs = minCookingTimeMs;
}

Cook::~Cook()
{

}


void Cook::Run()
{
    std::thread cookThread([this] {

        while (true)
        {

            this->state = CookState::GoingToFridge;

            std::unique_lock<std::mutex> fridgeLock(Containers::fridgeMutex);
            // if fridge does not have enough ingredients -> wait
            Cook::conditionVariable->wait(fridgeLock, [this] { 
                bool enoughIngredients = Containers::CheckIfEnoughIngredients(Cook::specializedInPancakeType);
                if(!enoughIngredients) this->state = CookState::WaitingForFridge;
                return enoughIngredients;
            });
            Containers::TakeIngredientsFromFridge(Cook::specializedInPancakeType);
            fridgeLock.unlock();

            this->state = CookState::Cooking;
            int timeToCook = Cook::randomGenerator.GetRandomNumber(minCookingTimeMs, maxCookingTimeMs);
            std::this_thread::sleep_for(std::chrono::milliseconds(timeToCook));

            this->state = CookState::GoingToBuffet;
            std::unique_lock<std::mutex> buffetLock(Containers::buffetMutex);
            Cook::conditionVariable->wait(buffetLock, [this] { 
                bool enoughSpaceInBuffet = Containers::buffet[Cook::specializedInPancakeType] < Containers::GetBuffetPancakesLimit(Cook::specializedInPancakeType);
                if(!enoughSpaceInBuffet) this->state = CookState::WaitingForBuffet;
                return enoughSpaceInBuffet
            });
            Containers::buffet[Cook::specializedInPancakeType]++;
            buffetLock.unlock();
        }
    });
    
    if(cookThread.joinable())
        cookThread.detach();
}