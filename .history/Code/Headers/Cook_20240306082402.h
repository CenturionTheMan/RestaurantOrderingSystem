#include "Enums/PancakesTypes.cpp"


class Cook
{
private:
    PancakeType specializedInPancakeType;
public:
    Cook(std::vector<PancakeType>& buffet, PancakeType pancakeTypeSpecialization);
    ~Cook();
};