
#include "Zombie.hpp"

Zombie::~Zombie()
{
    std::cout << name << " was destroyed\n";
}

void Zombie::announce(void)
{
    std::cout << name << ": ";
    std::cout << " BraiiiiiiinnnzzzZ...\n";
}
void    Zombie::set_the_name(std::string input)
{
    name = input;
}
std::string Zombie::get_the_name()
{
    return name;
}