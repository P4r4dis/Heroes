#include "../include/Paladin.hpp"

int main()
{
    Paladin paladin("Uther", 99);
    paladin.attack();
    paladin.special();
    paladin.rest();
    paladin.special();
    paladin.damage(50);
    return 0;
}