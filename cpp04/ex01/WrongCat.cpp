#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "WrongCat Default constructor called" << std::endl;
    this->type = "WrongCat";
}
WrongCat::WrongCat(const WrongCat &obj) : WrongAnimal(obj)
{
    std::cout << "WrongCat Copy constructor called" << std::endl;
    this->type = obj.type;
}
WrongCat &WrongCat::operator=(const WrongCat &obj)
{
    std::cout << "WrongCat Copy assignment operator called" << std::endl;
    if (this != &obj)
    {
        this->type = obj.type;
    }
    return *this;
}
WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor called" << std::endl;
}
void WrongCat::makeSound() const
{
    std::cout << "WrongMeow......" << std::endl;
}

