#ifndef     __TEST_ENCHANTER__
# define    __TEST_ENCHANTER__

#include "test_Peasant.hpp"

class                   Enchanter : virtual public Peasant
{
    public:
        Enchanter(const std::string &name, int power);
        ~Enchanter(void);

        int             attack(void);
        int             special(void);
        void            rest(void);

    protected:
    private:

};
#endif //   !__TEST_ENCHANTER__