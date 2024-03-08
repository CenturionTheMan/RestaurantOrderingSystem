#include "../Headers/Cook.h"


Cook::Cook(Manager& manager, PancakeType pancakeTypeSpecialization, int minCookingTimeMs, int maxCookingTimeMs)
{
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
    Cook::shouldAbort = true;
}


void Cook::Run()
{
    std::thread cookThread([this] {

        while (Cook::shouldAbort == false)
        {
            std::cout << PancakeTypeToString(Cook::specializedInPancakeType) << ": GOING TO FRIDGE" << std::endl;
            std::unique_lock<std::mutex> fridgeLock(Containers::fridgeMutex);
            Cook::conditionVariable->wait(fridgeLock, [this] { 
                return Containers::CheckIfEnoughIngredients(Cook::specializedInPancakeType);
            });
            Containers::TakeIngredientsFromFridge(Cook::specializedInPancakeType);
            fridgeLock.unlock();

            std::cout << PancakeTypeToString(Cook::specializedInPancakeType) << ": COOKING" << std::endl;

            int timeToCook = Cook::randomGenerator.GetRandomNumber(minCookingTimeMs, maxCookingTimeMs);
            std::this_thread::sleep_for(std::chrono::milliseconds(timeToCook));

            std::cout << PancakeTypeToString(Cook::specializedInPancakeType) << ": WAITING" << std::endl;
            
            std::unique_lock<std::mutex> buffetLock(Containers::buffetMutex);
            Cook::conditionVariable->wait(buffetLock, [this] { 
                return Containers::buffet[Cook::specializedInPancakeType] < Containers::GetBuffetPancakesLimit(Cook::specializedInPancakeType);
            });
            Containers::buffet[Cook::specializedInPancakeType]++;
            buffetLock.unlock();

            std::cout << PancakeTypeToString(Cook::specializedInPancakeType) << ": SERVED" << std::endl;
        }

        std::cout << "Cook thread finished" << std::endl;
    });
    
    if(cookThread.joinable())
        cookThread.detach();
}