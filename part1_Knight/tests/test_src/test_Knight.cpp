#include "../test_include/test_Knight.hpp"

Knight::Knight(const std::string &name, int power) : Peasant(name, power)
{
    std::cout << getName() << " vows to protect the kingdom." << std::endl;
}

// Knight::~Knight()
// {}

// int Knight::attack()
// {
//     setDamageAttack(20);
//     int damage = getDamageAttack();
//     setPower(getPower() - getCostAttack());
//     std::cout << "SWORD" << std::endl;
//     return damage;
// }