#ifndef     __TEST_ICHARACTER__
# define    __TEST_ICHARACTER__

#include "test_Peasant.hpp"

class                   ICharacter : virtual public Peasant
{
    public:
        ICharacter(const std::string &name, int power);
        ~ICharacter(void);

        int             attack(void);
        int             special(void);
        void            rest(void);

    protected:
    private:

};
#endif //   !__TEST_ICHARACTER__