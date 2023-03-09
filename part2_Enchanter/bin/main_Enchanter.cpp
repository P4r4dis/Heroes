#include "../include/Enchanter.hpp"

int main()
{
    Enchanter   E("Jainna", 50);

    E.attack();
    E.special();
    E.rest();
    std::cout << "REAL MAIN STARTING :" << std::endl;
    return 0;
}