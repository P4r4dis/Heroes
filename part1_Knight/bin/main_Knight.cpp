#include "../include/Knight.hpp"

int main()
{
    Knight      k("Thrall", 40);

    k.attack();
    k.special();
    k.rest();
    std::cout << "REAL MAIN STARTING :" << std::endl;

    Knight      knight("Arthur", 20);

    knight.attack();
    knight.special();
    knight.rest();
    knight.special();
    knight.damage(50);
    return 0;
}