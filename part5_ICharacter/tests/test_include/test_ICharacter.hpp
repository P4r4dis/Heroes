#ifndef     __TEST_ICHARACTER__
# define    __TEST_ICHARACTER__

#include <memory>

class                   ICharacter
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

    protected:
    private:

};
#endif //   !__TEST_ICHARACTER__