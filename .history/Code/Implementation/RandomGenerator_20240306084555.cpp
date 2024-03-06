#include "Headers/RandomGenerator.h"

RandomGenerator::RandomGenerator(int seed)
{
    std::mt19937 gen(seed); // seed the generator
    RandomGenerator::generator = gen;
}

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
    std::uniform_int_distribution<> distr(min, max);
    return distr(RandomGenerator::generator);
}