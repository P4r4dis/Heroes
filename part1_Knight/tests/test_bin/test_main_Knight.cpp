#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>

#include "../test_include/test_Peasant.hpp"
#include "../test_include/test_Knight.hpp"

void    redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Peasant, test_construction, .signal = SIGPIPE, .init = redirect_all_stdout)
{
    Peasant     peasant("Gildas", 42);

    cr_assert(peasant.getName() == "Gildas");
    cr_assert(peasant.getPower() == 42);
    peasant.setPower(150);
    cr_assert(peasant.getPower() == 100);
    cr_assert(peasant.getHp() == 100);
    peasant.setHp(150);
    cr_assert(peasant.getHp() == 100);
    cr_assert(peasant.getCostAttack() == 10);
    peasant.setCostAttack(15);
    cr_assert(peasant.getCostAttack() == 15);
    cr_assert(peasant.getCostSpecial() == 0);
    peasant.setCostSpecial(10);
    cr_assert(peasant.getCostSpecial() == 10);
    cr_assert(peasant.getCostRest() == 0);
    peasant.setCostRest(10);
    cr_assert(peasant.getCostRest() == 10);
    cr_assert(peasant.getDamageAttack() == 5);
    peasant.setDamageAttack(10);
    cr_assert(peasant.getDamageAttack() == 10);
    cr_assert(peasant.getDamageSpecial() == 0);
    peasant.setDamageSpecial(10);
    cr_assert(peasant.getDamageSpecial() == 10);
    peasant.~Peasant();
    cr_assert_stdout_eq_str("Gildas goes for an adventure.\nGildas is back to his crops.\n");
}

Test(Peasant, test_out_of_combat_and_power, .signal = SIGPIPE, .init = redirect_all_stdout)
{
    Peasant     peasant("Gildas", 0);
    peasant.attack();
    peasant.setHp(0);
    peasant.attack();

    peasant.~Peasant();
    cr_assert_stdout_eq_str("Gildas goes for an adventure.\n"
    "Gildas is out of power.\n"
    "Gildas is out of combat.\n"
    "Gildas is back to his crops.\n");
}

Test(Peasant, test_attack, .signal = SIGPIPE, .init = redirect_all_stdout)
{
    Peasant     peasant("Gildas", 100);

    cr_assert(peasant.attack() == 5);
    cr_assert(peasant.getPower() == 90);
    peasant.~Peasant();
    cr_assert_stdout_eq_str("Gildas goes for an adventure.\n"
    "Gildas tosses a stone.\n"
    "Gildas is back to his crops.\n");
}

Test(Peasant, test_special, .signal = SIGPIPE, .init = redirect_all_stdout)
{
    Peasant     peasant("Gildas", 100);

    cr_assert(peasant.special() == 0);
    cr_assert(peasant.getPower() == 100);
    peasant.~Peasant();
    cr_assert_stdout_eq_str("Gildas goes for an adventure.\n"
    "Gildas doesn't know any special move.\n"
    "Gildas is back to his crops.\n");
}

Test(Peasant, test_rest, .signal = SIGPIPE, .init = redirect_all_stdout)
{
    Peasant     peasant("Gildas", 100);
    peasant.setPower(70);
    cr_assert(peasant.getPower() == 70);
    peasant.rest();
    cr_assert(peasant.getPower() == 100);
    cr_assert(peasant.getRest() == 30);
    peasant.setRest(50);
    cr_assert(peasant.getRest() == 50);
    peasant.~Peasant();
    cr_assert_stdout_eq_str("Gildas goes for an adventure.\n"
    "Gildas takes a nap.\n"
    "Gildas is back to his crops.\n");
}

Test(Peasant, test_damage, .signal = SIGPIPE, .init = redirect_all_stdout)
{
    Peasant     peasant("Gildas", 100);

    cr_assert(peasant.getHp() == 100);
    peasant.damage(50);
    cr_assert(peasant.getHp() == 50);
    peasant.damage(100);
    cr_assert(peasant.getHp() == 0);

    peasant.~Peasant();
    cr_assert_stdout_eq_str("Gildas goes for an adventure.\n"
    "Gildas takes 50 damage.\n"
    "Gildas is out of combat.\n"
    "Gildas is back to his crops.\n");
}

Test(Peasant, test_mainFunction, .signal = SIGPIPE, .init = redirect_all_stdout)
{
    Peasant     peasant("Gildas", 42);

    peasant.damage(50);
    peasant.damage(100);
    peasant.damage(200);
    peasant.rest();

    peasant.~Peasant();
    cr_assert_stdout_eq_str("Gildas goes for an adventure.\n"
    "Gildas takes 50 damage.\n"
    "Gildas is out of combat.\n"
    "Gildas is out of combat.\n"
    "Gildas is out of combat.\n"
    "Gildas is back to his crops.\n");
}


Test(Knight, test_Knight_construction, .signal = SIGPIPE, .init = redirect_all_stdout)
{
    Knight      k("Arthur", 20);

    k.~Knight();
    cr_assert_stdout_eq_str("Arthur goes for an adventure.\n"
    "Arthur vows to protect the kingdom.\n"
    "Arthur takes off his armor.\n"
    "Arthur is back to his crops.\n");
}

Test(Knight, test_Knight_attack, .signal = SIGPIPE, .init = redirect_all_stdout)
{
    Knight      k("Arthur", 20);

    k.attack();
    k.attack();
    k.attack();
    k.setHp(0);
    k.attack();

    cr_assert(k.getPower() == 0);
    cr_assert(k.getDamageAttack() == 20);

    k.~Knight();
    cr_assert_stdout_eq_str("Arthur goes for an adventure.\n"
    "Arthur vows to protect the kingdom.\n"
    "Arthur strikes with his sword.\n"
    "Arthur strikes with his sword.\n"
    "Arthur is out of power.\n"
    "Arthur is out of combat.\n"
    "Arthur takes off his armor.\n"
    "Arthur is back to his crops.\n");
}

Test(Knight, test_Knight_special, .signal = SIGPIPE, .init = redirect_all_stdout)
{
    Knight      k("Arthur", 42);

    cr_assert(k.special() == 50);
    cr_assert(k.special() == 0);

    k.setHp(0);
    cr_assert(k.special() == 0);

    k.~Knight();
    cr_assert_stdout_eq_str("Arthur goes for an adventure.\n"
    "Arthur vows to protect the kingdom.\n"
    "Arthur impales his ennemy.\n"
    "Arthur is out of power.\n"
    "Arthur is out of combat.\n"
    "Arthur takes off his armor.\n"
    "Arthur is back to his crops.\n");
}

Test(Knight, test_Knight_rest, .signal = SIGPIPE, .init = redirect_all_stdout)
{
    Knight      k("Arthur", 0);

    cr_assert(k.getPower() == 0);
    k.special();
    k.rest();
    cr_assert(k.getPower() == 50);
    k.special();

    k.setHp(0);
    k.rest();

    k.~Knight();
    cr_assert_stdout_eq_str("Arthur goes for an adventure.\n"
    "Arthur vows to protect the kingdom.\n"
    "Arthur is out of power.\n"
    "Arthur eats.\n"
    "Arthur impales his ennemy.\n"
    "Arthur is out of combat.\n"
    "Arthur takes off his armor.\n"
    "Arthur is back to his crops.\n");
}

Test(Knight, test_Knight_destruction, .signal = SIGPIPE, .init = redirect_all_stdout)
{
    Knight      k("Arthur", 0);

    k.~Knight();
    cr_assert_stdout_eq_str("Arthur goes for an adventure.\n"
    "Arthur vows to protect the kingdom.\n"
    "Arthur takes off his armor.\n"
    "Arthur is back to his crops.\n");
}