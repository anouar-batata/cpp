#include "Contact.hpp"
#include <iomanip>
#include <cstdlib>

class   PhoneBook
{
    private:
        contact cts[8];
        int index;
        int size;
    public:
        PhoneBook();
        void    add();
        void    search();
        void    ft_exit();
        ~PhoneBook();

};