#ifndef     __TEST_KNIGHT__
# define    __TEST_KNIGHT__

#include "test_Peasant.hpp"

class                   Knight : virtual public Peasant
{
    public:
        Knight(const std::string &name, int power);
        // ~Knight();

        int             attack(void);
        int             special(void);
        void            rest(void);

    protected:
    private:

};
#endif //   !__TEST_KNIGHT__