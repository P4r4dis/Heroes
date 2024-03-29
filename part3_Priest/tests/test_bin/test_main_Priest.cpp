#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>

#include "../test_include/test_Peasant.hpp"
#include "../test_include/test_Priest.hpp"


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


Test(Priest, test_Priest_construction, .signal = SIGPIPE, .init = redirect_all_stdout)
{
    Priest      P("Trichelieu", 20);

    P.~Priest();
    cr_assert_stdout_eq_str("Trichelieu goes for an adventure.\n"
    "Trichelieu learns magic from his spellbook.\n"
    "Trichelieu enters in the order.\n"
    "Trichelieu finds peace.\n"
    "Trichelieu closes his spellbook.\n"
    "Trichelieu is back to his crops.\n");
}

Test(Priest, test_Priest_attack, .signal = SIGPIPE, .init = redirect_all_stdout)
{
    Priest      P("Trichelieu", 20);

    P.attack();
    P.setHp(0);
    P.attack();

    cr_assert(P.getPower() == 20);
    cr_assert(P.getDamageAttack() == 0);

    P.~Priest();
    cr_assert_stdout_eq_str("Trichelieu goes for an adventure.\n"
    "Trichelieu learns magic from his spellbook.\n"
    "Trichelieu enters in the order.\n"
    "Trichelieu don't know how to fight.\n"
    "Trichelieu is out of combat.\n"
    "Trichelieu finds peace.\n"
    "Trichelieu closes his spellbook.\n"
    "Trichelieu is back to his crops.\n");
}

Test(Priest, test_Priest_special, .signal = SIGPIPE, .init = redirect_all_stdout)
{
    Priest      P("Trichelieu", 50);

    cr_assert(P.special() == 99);
    cr_assert(P.special() == 0);

    P.setHp(0);
    cr_assert(P.special() == 0);

    P.~Priest();
    cr_assert_stdout_eq_str("Trichelieu goes for an adventure.\n"
    "Trichelieu learns magic from his spellbook.\n"
    "Trichelieu enters in the order.\n"
    "Trichelieu casts a fireball.\n"
    "Trichelieu is out of power.\n"
    "Trichelieu is out of combat.\n"
    "Trichelieu finds peace.\n"
    "Trichelieu closes his spellbook.\n"
    "Trichelieu is back to his crops.\n");
}

Test(Priest, test_Priest_rest, .signal = SIGPIPE, .init = redirect_all_stdout)
{
    Priest      P("Trichelieu", 20);

    cr_assert(P.getPower() == 20);
    P.special();
    P.rest();
    cr_assert(P.getPower() == 100);
    P.special();

    P.setHp(99);
    P.rest();
    cr_assert(P.getPower() == 100);
    cr_assert(P.getHp() == 100);


    P.~Priest();
    cr_assert_stdout_eq_str("Trichelieu goes for an adventure.\n"
    "Trichelieu learns magic from his spellbook.\n"
    "Trichelieu enters in the order.\n"
    "Trichelieu is out of power.\n"
    "Trichelieu prays.\n"
    "Trichelieu casts a fireball.\n"
    "Trichelieu prays.\n"
    "Trichelieu finds peace.\n"
    "Trichelieu closes his spellbook.\n"
    "Trichelieu is back to his crops.\n");
}

Test(Priest, test_Priest_main, .signal = SIGPIPE, .init = redirect_all_stdout)
{
    Priest      P("Trichelieu", 20);

    P.attack();
    P.special();
    P.rest();
    P.special();
    P.damage(50);
    cr_assert(P.getHp() == 50);

    P.~Priest();
    cr_assert_stdout_eq_str("Trichelieu goes for an adventure.\n"
    "Trichelieu learns magic from his spellbook.\n"
    "Trichelieu enters in the order.\n"
    "Trichelieu don't know how to fight.\n"
    "Trichelieu is out of power.\n"
    "Trichelieu prays.\n"
    "Trichelieu casts a fireball.\n"
    "Trichelieu takes 50 damage.\n"
    "Trichelieu finds peace.\n"
    "Trichelieu closes his spellbook.\n"
    "Trichelieu is back to his crops.\n");
}