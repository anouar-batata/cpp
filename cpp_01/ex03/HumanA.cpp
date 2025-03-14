#include "HumanA.hpp"

HumanA::HumanA(std::string str,Weapon &wp):wp1(wp),name(str)
{
    // std::cout << "constractor has been called";
}

void    HumanA::attack()
{
    std::cout << name << " attacks with their " << wp1.getType() << "\n";
}
