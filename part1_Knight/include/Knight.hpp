#ifndef         __KNIGHT__
# define        __KNIGHT__

#include "../include/Peasant.hpp"
class               Knight : public Peasant
{
    public:
        Knight(const std::string &name, int power);
        // ~Knight();

        int         attack(void);

    protected:
    private:

};
#endif //       !__KNIGHT__