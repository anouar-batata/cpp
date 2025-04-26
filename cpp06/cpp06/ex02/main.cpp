#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Cast.hpp"

int main()
{
    Base    *p; // create a pointeur of a obj

    p = generate(); //generate a randome derived objet given to the pointeur (polymorphisme) 
    identify(p); // detect the type of the base obj by the pointeur
    identify(*p); // detect the type of the base obj by a reference

    delete p;
}