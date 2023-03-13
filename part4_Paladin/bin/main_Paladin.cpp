#include "../include/Paladin.hpp"

int main()
{
    Paladin   P("Uth", 99);

    P.attack();
    P.special();
    std::cout << "REAL MAIN STARTING :" << std::endl;

    return 0;
}