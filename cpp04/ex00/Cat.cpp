#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat Default constructor called" << std::endl;
    this->type = "Cat";
}
Cat::Cat(const Cat &obj) : Animal(obj)
{
    std::cout << "Cat Copy constructor called" << std::endl;
    this->type = obj.type;
}
Cat &Cat::operator=(const Cat &obj)
{
    std::cout << "Cat Copy assignment operator called" << std::endl;
    if (this != &obj)
    {
        this->type = obj.type;
    }
    return *this;
}
Cat::~Cat()
{
    std::cout << "Cat Destructor called" << std::endl;
}
void Cat::makeSound() const
{
    std::cout << "Meow" << std::endl;
}



