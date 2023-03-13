#ifndef         __PALADIN__
# define        __PALADIN__

#include "../include/Peasant.hpp"
class                   Paladin : virtual public Peasant
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