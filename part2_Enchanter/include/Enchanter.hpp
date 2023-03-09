#ifndef         __ENCHANTER__
# define        __ENCHANTER__

#include "../include/Peasant.hpp"
class                   Enchanter : virtual public Peasant
{
    public:
        Enchanter(const std::string &name, int power);
        ~Enchanter(void);

        int             attack(void);
    protected:
    private:

};
#endif //       !__ENCHANTER__