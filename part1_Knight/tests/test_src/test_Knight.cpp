#include "../test_include/test_Knight.hpp"

Knight::Knight(const std::string &name, int power) : Peasant(name, power)
{
    std::cout << getName() << " vows to protect the kingdom." << std::endl;
}

int                     Knight::attack()
{
    int damage = getDamageAttack();

    if(getHp() <= 0)
    {
        std::cout << getName() << " is out of combat." << std::endl;

        return 0;
    }
    else if (getPower() >= 10)
    {
        setDamageAttack(20);
        setPower(getPower() - getCostAttack());
        std::cout << getName() << " strikes with his sword." << std::endl;
    }
    else
    {
        std::cout << getName() << " is out of power." << std::endl;

        return 0;
    }
    
    return damage;
}

int                     Knight::special()
{
    int damageSpecial = 0;

    if(getHp() <= 0)
    {
        std::cout << getName() << " is out of combat." << std::endl;

        return 0;
    }
    else if (getPower() >= 30)
    {
        setDamageSpecial(50);
        setCostSpecial(30);
        damageSpecial = getDamageSpecial();
        setPower(getPower() - getCostSpecial());
        std::cout << getName() << " impales his ennemy." << std::endl;
    }
    else
    {
        std::cout << getName() << " is out of power." << std::endl;

        return 0;
    }
    
    return damageSpecial;
}

void                    Knight::rest()
{
    if(getHp() <= 0)
        std::cout << getName() << " is out of combat." << std::endl;
    else
    {
        setRest(50);
        setPower(getPower() + getRest());
        std::cout << getName() << " eats." << std::endl;
    }
}