#ifndef         __PALADIN__
# define        __PALADIN__

#include "../include/Knight.hpp"
#include "../include/Enchanter.hpp"
#include "../include/Priest.hpp"


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
#endif //       !__PALADIN__