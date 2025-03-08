#include "Zombie.hpp"

void randomChump(std::string name)
{
    std::string str;
    Zombie  obj;
    str = name;
    obj.set_the_name(str);
    obj.announce();
}