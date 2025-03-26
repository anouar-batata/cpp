#include "Zombie.hpp"

// void    f()
// {
//     system("leaks a.out");
// }

int main()
{
    std::string foooo;
    Zombie *obj;


    foooo = "anouar";
    randomChump(foooo);

    obj = newZombie("said");
    obj->announce();
    delete(obj);

}