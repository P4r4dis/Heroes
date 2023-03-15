#ifndef             __TEST_POISONPOTION__
    #define         __TEST_POISONPOTION__

#include "test_IPotion.hpp"
class               PoisonPotion : public IPotion
{
    public:
        PoisonPotion(void);
        ~PoisonPotion(void);
};
#endif //           !__TEST_POISONPOTION__