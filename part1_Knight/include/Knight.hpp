#ifndef         __KNIGHT__
# define        __KNIGHT__

#include "../include/Peasant.hpp"
class                   Knight : virtual public Peasant
{
    public:
        Knight(const std::string &name, int power);
        // ~Knight();

        int             attack(void);
        int             special(void);

    protected:
    private:

};
#endif //       !__KNIGHT__