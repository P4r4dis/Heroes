#include "../include/Priest.hpp"

int main()
{
    Priest   E("Jainna", 50);

    E.attack();
    E.special();
    E.rest();
    std::cout << "REAL MAIN STARTING :" << std::endl;
    Priest      enchanter("Merlin", 20);

    enchanter.attack();
    enchanter.special();
    enchanter.rest();
    enchanter.special();
    enchanter.damage(50);
    return 0;
}