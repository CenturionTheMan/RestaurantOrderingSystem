#include <iomanip>
#include <random>
#include <windows.h>
class RandomGenerator
{
private:
    std::mt19937 generator;
public:
    RandomGenerator();
    ~RandomGenerator();

    /// @brief Function return random number within min, max - inclusive.
    /// @param min Min possible value
    /// @param max Max possible value
    /// @return Random number within boundaries
    int GetRandomNumber(int min, int max);
    
    /// @brief Function will return given amount of random number within min, max - inclusive.
    /// @param min Min possible value
    /// @param max Max possible value
    /// @param numberAmount Amount of numbers to return
    /// @return Pointer to array of random numbers
    int* GetRandomNumbers(int min, int max, int numberAmount);
};

RandomGenerator::RandomGenerator()
{
    LARGE_INTEGER seedByTicks;
    QueryPerformanceCounter(&seedByTicks);

    RandomGenerator::generator = std::mt19937(seedByTicks.QuadPart);
}


RandomGenerator::~RandomGenerator()
{

}

int RandomGenerator::GetRandomNumber(int min, int max)
{
    std::uniform_int_distribution<> dist(min, max);
    return dist(RandomGenerator::generator);
}

int* RandomGenerator::GetRandomNumbers(int min, int max, int numberAmount)
{
    std::uniform_int_distribution<> dist(min, max);
    int* arr = new int[numberAmount];
    for (int i = 0; i < numberAmount; i++)
    {
        arr[i] = dist(RandomGenerator::generator);
    }
    return arr;
}
