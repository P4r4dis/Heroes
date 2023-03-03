#include "../test_include/test_Peasant.hpp"

Peasant::Peasant(const std::string &name, int power)
    :   m_name(name), m_power((power > 100) ? power = 100 : power),
        m_hp(100), m_costAttack(10), m_costSpecial(0), m_costRest(0),
        m_damageAttack(5), m_damageSpecial(0)
{
    std::cout << m_name + " goes for an adventure." << std::endl;
}

Peasant::~Peasant(void)
{
    std::cout << m_name + " is back to his crops." << std::endl;
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

void                    Peasant::setPower(int power)
{
    (power > 100) ? m_power = 100 : m_power = power;
}

void                    Peasant::setHp(int hp)
{
    (hp > 100) ? m_hp = 100 : m_hp = hp;
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