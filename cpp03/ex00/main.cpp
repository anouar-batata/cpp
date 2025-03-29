#include "ClapTrap.hpp"


int main()
{
    ClapTrap claptrap1("ClapTrap1");
    ClapTrap claptrap2("ClapTrap2");

    claptrap1.attack(claptrap2.getName());
    claptrap2.takeDamage(claptrap1.getAttackDamage());

    claptrap2.beRepaired(5);
    claptrap2.attack(claptrap1.getName());
    claptrap1.takeDamage(claptrap2.getAttackDamage());

    return 0;
}
