#ifndef         __PRIEST__
# define        __PRIEST__

#include "../include/Peasant.hpp"
class                   Priest : virtual public Peasant
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
#endif //       !__PRIEST__