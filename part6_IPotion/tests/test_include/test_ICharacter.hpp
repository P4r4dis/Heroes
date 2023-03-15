#ifndef     __TEST_ICHARACTER__
# define    __TEST_ICHARACTER__

#include <iostream>
#include "test_HealthPotion.hpp"
#include "test_PowerPotion.hpp"
#include "test_PoisonPotion.hpp"

class                                   ICharacter
{
    public:
        virtual ~ICharacter(void);

        virtual int                     attack(void) = 0;
        virtual int                     special(void) = 0;
        virtual void                    rest(void) = 0;
        virtual void                    damage(int damage) = 0;
        virtual const std::string       &getName(void) const = 0;
        virtual int                     getHp(void) const = 0;
        virtual int                     getPower(void) const = 0;
        virtual void                    drink(const HealthPotion &healthPotion) = 0;
        virtual void                    drink(const PowerPotion &powerPotion) = 0;
        virtual void                    drink(const PoisonPotion &poisonPotion) = 0;
        virtual void                    drink(const IPotion &Potion) = 0;



    protected:
    private:

};
#endif //   !__TEST_ICHARACTER__