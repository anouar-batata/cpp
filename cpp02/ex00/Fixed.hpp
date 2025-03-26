
#include <iostream>


class Fixed
{
private:
    int  value;
    int static const b;
public:
    Fixed();
    Fixed(const Fixed &copy);
    Fixed &operator=(const Fixed &copy);
    ~Fixed();
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};