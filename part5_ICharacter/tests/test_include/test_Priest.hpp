#ifndef     __TEST_PRIEST__
# define    __TEST_PRIEST__

#include "test_Enchanter.hpp"

class                   Priest : virtual public Enchanter
{
    public:
        Priest(const std::string &name, int power);
        ~Priest(void);

        int             attack(void);
        int             special(void);
        void            rest(void);

    protected:
    private:

};
#endif //   !__TEST_PRIEST__