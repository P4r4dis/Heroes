#ifndef     __TEST_KNIGHT__
# define    __TEST_KNIGHT__

#include "test_Peasant.hpp"

class       Knight : public Peasant
{
    public:
        Knight(const std::string &name, int power);
        // ~Knight();

        int attack();

    protected:
    private:

};
#endif //   !__TEST_KNIGHT__