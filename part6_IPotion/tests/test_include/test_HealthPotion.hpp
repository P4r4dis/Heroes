#ifndef             __TEST_HEALTHPOTION__
    #define         __TEST_HEALTHPOTION__

#include "test_IPotion.hpp"
class               HealthPotion : virtual public IPotion
{
    public:
        HealthPotion();
        ~HealthPotion();
    protected:
    private:
};
#endif //           !__TEST_HEALTHPOTION__