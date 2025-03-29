#include "ScavTrap.hpp"


int main()
{
    ScavTrap scavtrap1("ScavTrap1");
    ScavTrap scavtrap2("ScavTrap2");

    scavtrap1.attack(scavtrap2.getName());
    scavtrap2.takeDamage(scavtrap1.getAttackDamage());

    scavtrap2.beRepaired(5);
    scavtrap2.attack(scavtrap1.getName());
    scavtrap1.takeDamage(scavtrap2.getAttackDamage());

    scavtrap1.guardGate();
    scavtrap2.guardGate();
    return 0;
}
