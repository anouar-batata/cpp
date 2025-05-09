
#include "brain.hpp"

Brain::Brain()
{
    std::cout << "Brain Default constructor called" << std::endl;
}
Brain::Brain(const Brain &obj)
{
    std::cout << "Brain Copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = obj.ideas[i];
}
Brain &Brain::operator=(const Brain &obj)
{
    std::cout << "Brain Copy assignment operator called" << std::endl;
    if (this != &obj)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = obj.ideas[i];
    }
    return *this;
}
Brain::~Brain()
{
    std::cout << "Brain Destructor called" << std::endl;
}

