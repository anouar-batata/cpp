#include "Cat.hpp"
#include "brain.hpp"

Cat::Cat()
{
    std::cout << "Cat Default constructor called" << std::endl;
    this->type = "Cat";
    this->brain = new Brain();
}
Cat::Cat(const Cat &obj) : Animal(obj)
{
    std::cout << "Cat Copy constructor called" << std::endl;
    this->type = obj.type;
    this->brain = new Brain(*obj.brain);
}
Cat &Cat::operator=(const Cat &obj)
{
    std::cout << "Cat Copy assignment operator called" << std::endl;
    if (this != &obj)
    {
        this->type = obj.type;
        delete this->brain;
        this->brain = new Brain(*obj.brain);
    }
    return *this;
}
Cat::~Cat()
{
    std::cout << "Cat Destructor called" << std::endl;
    delete this->brain;
}
void Cat::makeSound() const
{
    std::cout << "Meow" << std::endl;
}