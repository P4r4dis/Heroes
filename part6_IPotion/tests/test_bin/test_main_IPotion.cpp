#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>

#include "../test_include/test_HealthPotion.hpp"
#include "../test_include/test_PoisonPotion.hpp"
#include "../test_include/test_PowerPotion.hpp"
#include "../test_include/test_IPotion.hpp"
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

Test(IPotion, test_interface, .init = redirect_all_stdout)
{
    ICharacter      *peasant = new Peasant("Gildas", 42);

    PoisonPotion    poison_potion;
    // PowerPotion     power_potion;
    HealthPotion    health_potion;
    IPotion         &potion = health_potion;

    std::cout   << peasant->getName() << ": " << peasant->getHp() << "HP, "
                << peasant->getPower() << "PP." << std::endl;
    
    peasant->drink(poison_potion);

    std::cout   << peasant->getName() << ": " << peasant->getHp() << "HP, "
                << peasant->getPower() << "PP." << std::endl;

    peasant->drink(potion);

    std::cout   << peasant->getName() << ": " << peasant->getHp() << "HP, "
                << peasant->getPower() << "PP." << std::endl;

    delete peasant;
    cr_assert_stdout_eq_str("Gildas goes for an adventure.\n"
    "Gildas: 100HP, 42PP.\n"
    "Gildas has been poisoned.\n"
    "Gildas: 50HP, 42PP.\n"
    "Gildas drinks a mysterious potion.\n"
    "Gildas: 100HP, 42PP.\n"
    "Gildas is back to his crops.\n");
}
