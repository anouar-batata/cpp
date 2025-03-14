#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
    Zombie *obj;
    obj = new Zombie;
    obj->set_the_name(name);
    return(obj);
}