#include "Zombie.hpp"

Zombie::~Zombie()
{

}

void Zombie::announce(void)
{
    std::cout << name << ": ";
    std::cout << " BraiiiiiiinnnzzzZ...";
}
void    Zombie::set_the_name(std::string input)
{
    name = input;
}
std::string Zombie::get_the_name()
{
    return name;
}