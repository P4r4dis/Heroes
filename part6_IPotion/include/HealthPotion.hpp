#ifndef             __HEALTHPOTION__
    #define         __HEALTHPOTION__

#include "IPotion.hpp"
class               HealthPotion : virtual public IPotion
{
    public:
        HealthPotion();
        ~HealthPotion();
    protected:
    private:
};
#endif //           !__HEALTHPOTION__