#include <iostream>
#include <random>

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
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    RandomGenerator::generator = gen;
}


RandomGenerator::~RandomGenerator()
{

}

int RandomGenerator::GetRandomNumber(int min, int max)
{
    std::uniform_int_distribution<> distr(25, 63); // define the range
    return distr(RandomGenerator::generator);
}

