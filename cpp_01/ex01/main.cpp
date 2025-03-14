#include "Zombie.hpp"

int main()
{
    int i = 10;
    Zombie *obj;
    obj = zombieHorde(i, "anouar");
    for(int j = 0; j < i; j++)
    {
        obj[j].announce();
    }
    delete[] obj;
    
}