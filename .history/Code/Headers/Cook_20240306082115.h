#include "Enums/PancakesTypes.cpp"


class Cook
{
private:
    PancakeType specializedInPancakeType;
public:
    Cook(PancakeType pancakeTypeSpecialization);
    ~Cook();
};