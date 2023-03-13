#include "../include/Paladin.hpp"

int main()
{
    Paladin   E("Jainna", 50);

    E.attack();
    E.special();
    E.rest();
    std::cout << "REAL MAIN STARTING :" << std::endl;
    Paladin      enchanter("Merlin", 20);

    enchanter.attack();
    enchanter.special();
    enchanter.rest();
    enchanter.special();
    enchanter.damage(50);
    return 0;
}