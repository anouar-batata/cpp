#include "Fixed.hpp"

int static const b = 8;

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
    std::cout << "copy constructor called" << std::endl;
    (*this) = copy;
}

Fixed &Fixed::operator=(const Fixed &src)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &src)
        this->value = src.getRawBits();
    return(*this);
}

void    Fixed::setRawBits( int const raw )
{
    this->value = raw;
}
int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return(this->value);
}
