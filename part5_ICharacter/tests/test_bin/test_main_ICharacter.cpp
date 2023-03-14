#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>

#include "../test_include/test_ICharacter.hpp"
#include "../test_include/test_Peasant.hpp"
#include "../test_include/test_Knight.hpp"
#include "../test_include/test_Enchanter.hpp"
#include "../test_include/test_Priest.hpp"
#include "../test_include/test_Paladin.hpp"

void    redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(ICharacter, test_main, .init = redirect_all_stdout)
{
    ICharacter *peasant = new Peasant("Gildas", 42);
    ICharacter *knight = new Knight("Arthur", 20);
    ICharacter *enchanter = new Enchanter("Merlin" , 20);
    ICharacter *priest = new Priest("Trichelieu", 20);
    ICharacter *paladin = new Paladin("Uther", 99);

    peasant->attack();
    knight->special();
    enchanter->rest();
    priest->damage(21);
    std::cout   << paladin->getName() << ": "
                << paladin->getHp() << " health points, "
                << paladin->getPower() << " power points."
                << std::endl;
    delete peasant;
    delete knight;
    delete enchanter;
    delete priest;
    delete paladin;

    cr_assert_stdout_eq_str("Gildas goes for an adventure.\n"
        "Arthur goes for an adventure.\n"
        "Arthur vows to protect the kingdom.\n"
        "Merlin goes for an adventure.\n"
        "Merlin learns magic from his spellbook.\n"
        "Trichelieu goes for an adventure.\n"
        "Trichelieu learns magic from his spellbook.\n"
        "Trichelieu enters in the order.\n"
        "Uther goes for an adventure.\n"
        "Uther vows to protect the kingdom.\n"
        "Uther learns magic from his spellbook.\n"
        "Uther enters in the order.\n"
        "Uther fights for the light.\n"
        "Gildas tosses a stone.\n"
        "Arthur is out of power.\n"
        "Merlin meditates.\n"
        "Trichelieu takes 21 damage.\n"
        "Uther: 100 health points, 99 power points.\n"
        "Gildas is back to his crops.\n"
        "Arthur takes off his armor.\n"
        "Arthur is back to his crops.\n"
        "Merlin closes his spellbook.\n"
        "Merlin is back to his crops.\n"
        "Trichelieu finds peace.\n"
        "Trichelieu closes his spellbook.\n"
        "Trichelieu is back to his crops.\n"
        "Uther is blessed.\n"
        "Uther finds peace.\n"
        "Uther closes his spellbook.\n"
        "Uther takes off his armor.\n"
        "Uther is back to his crops.\n"
        );
}
