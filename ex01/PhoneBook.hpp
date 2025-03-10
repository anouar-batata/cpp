#include "Contact.hpp"
#include <iomanip>
#include <cstdlib>



#ifndef PhoneBook_HPP
# define PhoneBook_HPP
class   PhoneBook
{
    private:
        Contact cts[8];
        int index;
        int size;
    public:
        PhoneBook();
        void    add();
        void    search();
        void    ft_exit();

};
#endif 