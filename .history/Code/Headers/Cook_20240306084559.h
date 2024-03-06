#include "Enums/PancakesTypes.cpp"
#include <vector>
#include <thread>

class Cook
{
private:
    PancakeType specializedInPancakeType;
    int maxCookingTimeMs;
    int minCookingTimeMs;
    
    bool isReadyToServe = false;



    void CookPancake();
    void ServePancake();
public:
    Cook(std::vector<PancakeType>& buffet, PancakeType pancakeTypeSpecialization, int maxCookingTimeMs, int minCookingTimeMs);
    ~Cook();

    void Run();
};

void Cook::CookPancake()
{
    std::this_thread::sleep_for(std::chrono::milliseconds());
}

void Cook::Run()
{
    while (true)
    {
        Cook::CookPancake();
        Cook::ServePancake();
    }
}


