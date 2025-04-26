#include "Cast.hpp"

Base * generate(void)
{
    std::srand(std::time(NULL));
    int random = std::rand() % 3;
    switch (random)
    {
    case 0:
        return(new A);
    case 1:
        return(new B);
    case 2:
        return(new C);

    default: // just for safety
        return NULL;
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "the objet is of type A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "the objet is of type B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "the objet is of type C" << std::endl;
    else
        std::cout << "type unknown" << std::endl;
}

void identify(Base& p)
{
    try
    {
        dynamic_cast<A &>(p);
        std::cout << "the objet is of type A" << std::endl;
    }
    catch(std::exception &e)
    {
        try
        {
            dynamic_cast<B &>(p);
            std::cout << "the objet is of type B" << std::endl;
        }
        catch(const std::exception& e)
        {
            try
            {
                dynamic_cast<C &>(p);
                std::cout << "the objet is of type C" << std::endl;
            }
            catch(const std::exception& e)
            {
                std::cerr << "type unknown" << std::endl;
            }
        }
    }
}