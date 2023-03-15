#include "../test_include/test_Peasant.hpp"

Peasant::Peasant(const std::string &name, int power)
    :   m_name(name), m_power((power > 100) ? power = 100 : power),
        m_hp(100), m_costAttack(10), m_costSpecial(0), m_costRest(0),
        m_damageAttack(5), m_damageSpecial(0), m_rest(30)
{
    std::cout << m_name << " goes for an adventure." << std::endl;
}

Peasant::~Peasant(void)
{
    std::cout << m_name << " is back to his crops." << std::endl;
}

const std::string       &Peasant::getName(void) const
{
    return m_name;
}

int                     Peasant::getPower(void) const
{
    return m_power;
}

int                     Peasant::getHp(void) const
{
    return m_hp;
}

int                     Peasant::getCostAttack(void) const
{
    return m_costAttack;
}

int                     Peasant::getCostSpecial(void) const
{
    return m_costSpecial;
}

int                     Peasant::getCostRest(void) const
{
    return m_costRest;
}

int                     Peasant::getDamageAttack(void) const
{
    return m_damageAttack;
}

int                     Peasant::getDamageSpecial(void) const
{
    return m_damageSpecial;
}

int                     Peasant::getRest(void) const
{
    return m_rest;
}

void                    Peasant::setPower(int power)
{
    (power > 100) ? m_power = 100 : m_power = power;
    if (m_power <= 0)
        m_power = 0;

}

void                    Peasant::setHp(int hp)
{
    (hp > 100) ? m_hp = 100 : m_hp = hp;
    if (m_hp <= 0)
        m_hp = 0;
}

void                    Peasant::setCostAttack(int costAttack)
{
    m_costAttack = costAttack;
}

void                    Peasant::setCostSpecial(int costSpecial)
{
    m_costSpecial = costSpecial;
}

void                    Peasant::setCostRest(int costRest)
{
    m_costRest = costRest;
}

void                    Peasant::setDamageAttack(int damageAttack)
{
    m_damageAttack = damageAttack;
}

void                    Peasant::setDamageSpecial(int damageSpecial)
{
    m_damageSpecial = damageSpecial;
}

void                    Peasant::setRest(int rest)
{
    m_rest = rest;
}

int                     Peasant::attack()
{
    if (m_hp <= 0)
    {
        std::cout << m_name << " is out of combat." << std::endl;

        return 0;
    }
    else if (m_power >= 10)
    {
        m_power -= m_costAttack;
        std::cout << m_name << " tosses a stone." << std::endl;

        return m_damageAttack;

    }
    else
    {
        std::cout << m_name << " is out of power." << std::endl;

        return 0;
    }    
}

int                     Peasant::special()
{
    if (m_hp <= 0)
    {
        std::cout << m_name << " is out of combat.2" << std::endl;

        return 0;
    }
    else
    {
        m_power -= m_costSpecial;
        std::cout << m_name << " doesn't know any special move." << std::endl;

        return m_damageSpecial;
    }
}

void                    Peasant::rest()
{
    if (m_hp > 0)
    {
        m_power -= m_costRest;
        m_power += m_rest;
        if (m_power > 100)
            m_power = 100;
        std::cout << m_name << " takes a nap." << std::endl;
    }
    else
        std::cout << m_name << " is out of combat." << std::endl;
}

void                    Peasant::damage(int damage)
{
    m_hp -= damage;
    if (m_hp <= 0)
    {
        m_hp = 0;
        std::cout << m_name << " is out of combat." << std::endl;
    }
    else
        std::cout << m_name << " takes " << damage << " damage." << std::endl;
}

void                    Peasant::drink(const HealthPotion &potion)
{
    setHp(m_hp + potion.getHealthPotion());
    std::cout << m_name <<  " feels rejuvenated." << std::endl;
}

void                    Peasant::drink(const PowerPotion &potion)
{
    setPower(m_power + potion.getPowerPotion());
    std::cout << m_name <<  " power is restored." << std::endl;
}

void                    Peasant::drink(const PoisonPotion &potion)
{
    setHp(m_hp - potion.getPoisonPotion());
    std::cout << m_name << " has been poisoned." << std::endl;
}

void                    Peasant::drink(const IPotion &potion)
{
    setHp(m_hp + potion.getHealthPotion());
    std::cout << m_name << " drinks a mysterious potion." << std::endl;
}