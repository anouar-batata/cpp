#include "Dog.hpp"
#include "brain.hpp"

Dog::Dog()
{
    std::cout << "Dog Default constructor called" << std::endl;
    this->type = "Dog";
    this->brain = new Brain();
}
Dog::Dog(const Dog &obj) : Animal(obj)
{
    std::cout << "Dog Copy constructor called" << std::endl;
    this->type = obj.type;
    this->brain = new Brain(*obj.brain);
}
Dog &Dog::operator=(const Dog &obj)
{
    std::cout << "Dog Copy assignment operator called" << std::endl;
    if (this != &obj)
    {
        this->type = obj.type;
        delete this->brain;
        this->brain = new Brain(*obj.brain);
    }
    return *this;
}
Dog::~Dog()
{
    std::cout << "Dog Destructor called" << std::endl;
    delete this->brain;
}
void Dog::makeSound() const
{
    std::cout << "dog sound..." << std::endl;
}