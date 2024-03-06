#include "Enums/PancakesTypes.cpp"
#include <vector>


class Cook
{
private:
    PancakeType specializedInPancakeType;
    bool isReadyToServe = false;
public:
    Cook(std::vector<PancakeType>& buffet, PancakeType pancakeTypeSpecialization);
    ~Cook();

    void cookPancake();
};


