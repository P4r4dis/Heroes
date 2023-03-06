#include "../include/Peasant.hpp"

int main()
{
    Peasant     p("Gildas", 42);

    std::cout << "p.getName = " << p.getName() << std::endl;


    std::cout << "p.getPower = " << p.getPower() << std::endl;
    p.setPower(-10);
    std::cout << "p.getPower after p.setPower = " << p.getPower() << std::endl;
    std::cout << "p.getPower = " << p.getPower() << std::endl;
    p.setPower(150);
    std::cout << "p.getPower after p.setPower = " << p.getPower() << std::endl;

    std::cout << "p.getHp = " << p.getHp() << std::endl;
    p.setHp(-150);
    std::cout << "p.getHp after p.setHp = " << p.getHp() << std::endl;
    std::cout << "p.getHp = " << p.getHp() << std::endl;
    p.setHp(150);
    std::cout << "p.getHp after p.setHp = " << p.getHp() << std::endl;

    std::cout << "p.getCostAttack = " << p.getCostAttack() << std::endl;
    p.setCostAttack(20);
    std::cout << "p.getCostAttack after setCostAttack = " << p.getCostAttack() << std::endl;

    std::cout << "p.getCostSpecial = " << p.getCostSpecial() << std::endl;
    p.setCostSpecial(20);
    std::cout << "p.getCostSpecial after setCostSpecial = " << p.getCostSpecial() << std::endl;

    std::cout << "p.getCostRest = " << p.getCostRest() << std::endl;
    p.setCostRest(20);
    std::cout << "p.getCostRest after setCostRest = " << p.getCostRest() << std::endl;

    std::cout << "p.getDamageAttack = " << p.getDamageAttack() << std::endl;
    p.setDamageAttack(20);
    std::cout << "p.getDamageAttack after setDamageAttack = " << p.getDamageAttack() << std::endl;

    std::cout << "p.getDamageSpecial = " << p.getDamageSpecial() << std::endl;
    p.setDamageSpecial(20);
    std::cout << "p.getDamageSpecial after setDamageSpecial = " << p.getDamageSpecial() << std::endl;

    std::cout << "p.attack = " << p.attack() << std::endl;
    std::cout << "p.getPower aftter p.attack = " << p.getPower() << std::endl;
    return 0;
}