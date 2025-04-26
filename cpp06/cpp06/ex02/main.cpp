#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Cast.hpp"

int main()
{
    Base    *p; // create a pointeur of a obj

    p = generate(); //generate a randome derive objet given to the pointeur (polymorphisme) 
    identify(p); // detect the type of the pointeur (which one in the derive clasess using a pointeur)
    identify(*p); // detect the type of the pointeur (which one in the derive clasess using a reference)

    delete p;
}