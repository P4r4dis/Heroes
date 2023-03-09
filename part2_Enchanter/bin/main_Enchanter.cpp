#include "../include/Enchanter.hpp"

int main()
{
    Enchanter   E("Jainna", 50);

    E.attack();
    E.special();
    std::cout << "REAL MAIN STARTING :" << std::endl;
    return 0;
}