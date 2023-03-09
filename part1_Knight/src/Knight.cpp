#include "../include/Knight.hpp"

Knight::Knight(const std::string &name, int power) : Peasant(name, power)
{}

int                     Knight::attack()
{
    int damage = getDamageAttack();

    setDamageAttack(20);
    setPower(getPower() - getCostAttack());
    std::cout << getName() << " strikes with his sword." << std::endl;
    
    return damage;
}