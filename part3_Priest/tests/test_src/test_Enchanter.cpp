#include "../test_include/test_Enchanter.hpp"

Enchanter::Enchanter(const std::string &name, int power) : Peasant(name, power)
{
    std::cout << getName() << " learns magic from his spellbook." << std::endl;
}

Enchanter::~Enchanter()
{
    std::cout << getName() << " closes his spellbook." << std::endl;
}

int                     Enchanter::attack()
{
    if(getHp() <= 0)
    {
        std::cout << getName() << " is out of combat." << std::endl;

        return 0;
    }
    else
    {
        setDamageAttack(0);
        setCostAttack(0);
        setPower(getPower() - getCostAttack());
        std::cout << getName() << " don't know how to fight." << std::endl;
        return getDamageAttack();
    }
}

int                     Enchanter::special()
{
    int damageSpecial = 0;

    if(getHp() <= 0)
    {
        std::cout << getName() << " is out of combat." << std::endl;

        return 0;
    }
    else if (getPower() >= 50)
    {
        setDamageSpecial(99);
        setCostSpecial(50);
        damageSpecial = getDamageSpecial();
        setPower(getPower() - getCostSpecial());
        std::cout << getName() << " casts a fireball." << std::endl;
    }
    else
    {
        std::cout << getName() << " is out of power." << std::endl;

        return 0;
    }
    
    return damageSpecial;
}

void                    Enchanter::rest()
{
    if(getHp() <= 0)
        std::cout << getName() << " is out of combat." << std::endl;
    else
    {
        setRest(100);
        setPower(getPower() + getRest());
        std::cout << getName() << " meditates." << std::endl;
    }
}