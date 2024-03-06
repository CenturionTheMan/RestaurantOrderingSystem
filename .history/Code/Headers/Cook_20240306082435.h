#include "Enums/PancakesTypes.cpp"
#include <vector>


class Cook
{
private:
    PancakeType specializedInPancakeType;
public:
    Cook(std::vector<PancakeType> buffet, PancakeType pancakeTypeSpecialization);
    ~Cook();
};

Cook::Cook(std::vector<PancakeType> buffet, PancakeType pancakeTypeSpecialization)
{
    Cook::specializedInPancakeType = pancakeTypeSpecialization;
}

Cook::~Cook()
{
}
