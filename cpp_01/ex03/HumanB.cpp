#include "HumanB.hpp"

HumanB::HumanB(std::string str):wp2(NULL),name(str)
{
    // std::cout << "constractor has been called \n";
}


void    HumanB::attack()
{
    if(wp2 == NULL)
        std::cout << name << " cant attack\n";
    else
        std::cout << name << " attacks with their " << wp2->getType() << "\n";
}

void HumanB::setWeapon(Weapon &input)
{
    wp2 = &input;
}