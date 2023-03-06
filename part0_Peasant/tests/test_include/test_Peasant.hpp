#ifndef             __TEST_PEASANT__
# define            __TEST_PEASANT__

#include <string>
#include <iostream>
class                       Peasant
{
    public:
        Peasant(const std::string &name, int power);
        ~Peasant(void);

        const std::string   &getName(void) const;
        int                 getPower(void) const;
        int                 getHp(void) const;
        int                 getCostAttack(void) const;
        int                 getCostSpecial(void) const;
        int                 getCostRest(void) const;
        int                 getDamageAttack(void) const;
        int                 getDamageSpecial(void) const;
        int                 getRest(void) const;

        void                setPower(int power);
        void                setHp(int hp);
        void                setCostAttack(int costAttack);
        void                setCostSpecial(int costSpecial);
        void                setCostRest(int costRest);
        void                setDamageAttack(int DamageAttack);
        void                setDamageSpecial(int DamageSpecial);
        void                setRest(int rest);

        int                 attack(void);
        int                 special(void);
        void                rest(void);

        void                damage(int damage);
    protected:
    private:
        const std::string   m_name;
        int                 m_power;
        int                 m_hp;
        int                 m_costAttack;
        int                 m_costSpecial;
        int                 m_costRest;
        int                 m_damageAttack;
        int                 m_damageSpecial;
        int                 m_rest;
};
#endif //          !__TEST_PEASANT__