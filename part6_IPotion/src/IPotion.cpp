#include "../include/IPotion.hpp"

IPotion::~IPotion(void)
{}

int IPotion::getHealthPotion(void) const
{
    return m_healthPotion;
}

void    IPotion::setHealthPotion(int healthPotion)
{
    m_healthPotion = healthPotion;
}

int IPotion::getPowerPotion(void) const
{
    return m_powerPotion;
}

void    IPotion::setPowerPotion(int powerPotion)
{
    m_powerPotion = powerPotion;
}

int IPotion::getPoisonPotion(void) const
{
    return m_poisonPotion;
}

void    IPotion::setPoisonPotion(int poisonPotion)
{
    m_poisonPotion = poisonPotion;
}