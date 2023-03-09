#include "../include/Knight.hpp"

Knight::Knight(const std::string &name, int power) : Peasant(name, power)
{
    std::cout << getName() << " vows to protect the kingdom." << std::endl;
}

int                     Knight::attack()
{
    int damage = getDamageAttack();

    if(getHp() <= 0)
        std::cout << getName() << " is out of combat." << std::endl;
    else if (getPower() >= 10)
    {
        setDamageAttack(20);
        setPower(getPower() - getCostAttack());
        std::cout << getName() << " strikes with his sword." << std::endl;
    }
    else
        std::cout << getName() << " is out of power." << std::endl;
    
    return damage;
}