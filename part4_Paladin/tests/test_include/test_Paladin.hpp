#ifndef         __TEST_PALADIN__
# define        __TEST_PALADIN__

#include "../test_include/test_Knight.hpp"
#include "../test_include/test_Enchanter.hpp"
#include "../test_include/test_Priest.hpp"

class                   Paladin :   virtual public Knight, 
                                    virtual public Enchanter, 
                                    virtual public Priest
{
    public:
        Paladin(const std::string &name, int power);
        ~Paladin(void);

        int             attack(void);
        int             special(void);
        void            rest(void);

    protected:
    private:

};
#endif //       !__TEST_PALADIN__