#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog Default constructor called" << std::endl;
    this->type = "Dog";
}
Dog::Dog(const Dog &obj) : Animal(obj)
{
    std::cout << "Dog Copy constructor called" << std::endl;
    this->type = obj.type;
}
Dog &Dog::operator=(const Dog &obj)
{
    std::cout << "Dog Copy assignment operator called" << std::endl;
    if (this != &obj)
    {
        this->type = obj.type;
    }
    return *this;
}
Dog::~Dog()
{
    std::cout << "Dog Destructor called" << std::endl;
}
void Dog::makeSound() const
{
    std::cout << "dog sound..." << std::endl;
}