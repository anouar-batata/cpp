#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal Default constructor called" << std::endl;
    this->type = " ";
}
Animal::Animal(const Animal &obj)
{
    std::cout << "Animal Copy constructor called" << std::endl;
    this->type = obj.type;
}
Animal &Animal::operator=(const Animal &obj)
{
    std::cout << "Animal Copy assignment operator called" << std::endl;
    if (this != &obj)
    {
        this->type = obj.type;
    }
    return *this;
}
Animal::~Animal()
{
    std::cout << "Animal Destructor called" << std::endl;
}

std::string Animal::getType() const
{
    return this->type;
}
void Animal::makeSound() const
{
    std::cout << "Animal sound" << std::endl;
}