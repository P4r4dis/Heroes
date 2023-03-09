#include "../include/Knight.hpp"

int main()
{
    std::cout << "REAL MAIN STARTING :" << std::endl;
    Knight      k("Thrall", 40);

    k.attack();
    k.special();
    k.rest();
    return 0;
}