#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>

#include "../test_include/test_Peasant.hpp"
#include "../test_include/test_Enchanter.hpp"


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


Test(Enchanter, test_Enchanter_construction, .signal = SIGPIPE, .init = redirect_all_stdout)
{
    Enchanter      E("Merlin", 20);

    E.~Enchanter();
    cr_assert_stdout_eq_str("Merlin goes for an adventure.\n"
    "Merlin learns magic from his spellbook.\n"
    "Merlin closes his spellbook.\n"
    "Merlin is back to his crops.\n");
}

Test(Enchanter, test_Enchanter_attack, .signal = SIGPIPE, .init = redirect_all_stdout)
{
    Enchanter      E("Merlin", 20);

    E.attack();
    E.setHp(0);
    E.attack();

    cr_assert(E.getPower() == 20);
    cr_assert(E.getDamageAttack() == 0);

    E.~Enchanter();
    cr_assert_stdout_eq_str("Merlin goes for an adventure.\n"
    "Merlin learns magic from his spellbook.\n"
    "Merlin don't know how to fight.\n"
    "Merlin is out of combat.\n"
    "Merlin closes his spellbook.\n"
    "Merlin is back to his crops.\n");
}

// Test(Enchanter, test_Enchanter_special, .signal = SIGPIPE, .init = redirect_all_stdout)
// {
//     Enchanter      E("Merlin", 42);

//     cr_assert(E.special() == 50);
//     cr_assert(E.special() == 0);

//     E.setHp(0);
//     cr_assert(E.special() == 0);

//     E.~Enchanter();
//     cr_assert_stdout_eq_str("Merlin goes for an adventure.\n"
//     "Merlin learns magic from his spellbook.\n"
//     "Merlin impales his ennemy.\n"
//     "Merlin is out of power.\n"
//     "Merlin is out of combat.\n"
//     "Merlin closes his spellbook.\n"
//     "Merlin is back to his crops.\n");
// }

// Test(Enchanter, test_Enchanter_rest, .signal = SIGPIPE, .init = redirect_all_stdout)
// {
//     Enchanter      E("Merlin", 0);

//     cr_assert(E.getPower() == 0);
//     E.special();
//     E.rest();
//     cr_assert(E.getPower() == 50);
//     E.special();

//     E.setHp(0);
//     E.rest();

//     E.~Enchanter();
//     cr_assert_stdout_eq_str("Merlin goes for an adventure.\n"
//     "Merlin learns magic from his spellbook.\n"
//     "Merlin is out of power.\n"
//     "Merlin eats.\n"
//     "Merlin impales his ennemy.\n"
//     "Merlin is out of combat.\n"
//     "Merlin closes his spellbook.\n"
//     "Merlin is back to his crops.\n");
// }

// Test(Enchanter, test_Enchanter_destruction, .signal = SIGPIPE, .init = redirect_all_stdout)
// {
//     Enchanter      E("Merlin", 0);

//     E.~Enchanter();
//     cr_assert_stdout_eq_str("Merlin goes for an adventure.\n"
//     "Merlin learns magic from his spellbook.\n"
//     "Merlin closes his spellbook.\n"
//     "Merlin is back to his crops.\n");
// }

// Test(Enchanter, test_Enchanter_main, .signal = SIGPIPE, .init = redirect_all_stdout)
// {
//     Enchanter      E("Merlin", 20);

//     E.attack();
//     E.special();
//     E.rest();
//     E.special();
//     E.damage(50);
//     cr_assert(E.getHp() == 50);

//     E.~Enchanter();
//     cr_assert_stdout_eq_str("Merlin goes for an adventure.\n"
//     "Merlin learns magic from his spellbook.\n"
//     "Merlin don't know how to fight.\n"
//     "Merlin is out of power.\n"
//     "Merlin eats.\n"
//     "Merlin impales his ennemy.\n"
//     "Merlin takes 50 damage.\n"
//     "Merlin closes his spellbook.\n"
//     "Merlin is back to his crops.\n");
// }