#include "../test_include/test_Knight.hpp"

Knight::Knight(const std::string &name, int power) : Peasant(name, power)
{
    std::cout << getName() << " vows to protect the kingdom." << std::endl;
}

// Knight::~Knight()
// {}

int                     Knight::attack()
{
    int damage = getDamageAttack();

    setDamageAttack(20);
    setPower(getPower() - getCostAttack());
    std::cout << getName() << " strikes with his sword." << std::endl;
    
    return damage;
}