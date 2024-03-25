#include "../Headers/Cook.h"

RandomGenerator Cook::randomGenerator = RandomGenerator();

Cook::Cook(Manager& manager, PancakeType pancakeTypeSpecialization, int minCookingTimeMs, int maxCookingTimeMs)
{
    this->state = CookState::CookIdle;

    Cook::randomGenerator = RandomGenerator();
    switch (pancakeTypeSpecialization)
    {
        case PancakeType::BananaPancakes:
            Cook::conditionVariable = &manager.CooksBananaPancakesLimitCondition;
            break;
        case PancakeType::BlueberryPancakes:
            Cook::conditionVariable = &manager.CooksBlueberryPancakesLimitCondition;
            break;
        case PancakeType::ChocolatePancakes:
            Cook::conditionVariable = &manager.CooksChocolatePancakesLimitCondition;
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

        while (this->isStopRequested == false)
        {
            this->state = CookState::GoingToFridge;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            if(this->isStopRequested) break;

            this->state = CookState::WaitingForFridge;
            std::unique_lock<std::mutex> fridgeLock(Containers::fridgeMutex);
            Cook::conditionVariable->wait(fridgeLock, [this] { 
                if(this->isStopRequested) return true;
                return Containers::CheckIfEnoughIngredients(Cook::specializedInPancakeType);
            });
            if(this->isStopRequested) break;

            Containers::TakeIngredientsFromFridge(Cook::specializedInPancakeType);
            fridgeLock.unlock();

            this->state = CookState::Cooking;
            int timeToCook = Cook::randomGenerator.GetRandomNumber(minCookingTimeMs, maxCookingTimeMs);
            std::this_thread::sleep_for(std::chrono::milliseconds(timeToCook));
            if(this->isStopRequested) break;

            this->state = CookState::CookGoingToBuffet;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));

            this->state = CookState::CookWaitingForBuffet;
            std::unique_lock<std::mutex> buffetLock(Containers::buffetMutex);
            Cook::conditionVariable->wait(buffetLock, [this] { 
                if(this->isStopRequested) return true;
                return Containers::buffet[Cook::specializedInPancakeType] < Containers::GetBuffetPancakesLimit(Cook::specializedInPancakeType);
            });
            if(this->isStopRequested) break;
            
            Containers::buffet[Cook::specializedInPancakeType]++;
            buffetLock.unlock();
        }
    });
    
    if(cookThread.joinable())
        cookThread.detach();
}