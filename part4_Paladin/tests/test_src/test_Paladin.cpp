#include "../test_include/test_Paladin.hpp"

Paladin::Paladin(const std::string &name, int power) :  Peasant(name, power),
                                                        Knight(name, power),
                                                        Enchanter(name, power),
                                                        Priest(name, power)
{
    std::cout << getName() << " fights for the light." << std::endl;
}

Paladin::~Paladin(void)
{
    std::cout << getName() << " is blessed." << std::endl;
}

int     Paladin::attack()
{
    return Knight::attack();
}