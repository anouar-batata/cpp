#include "Contact.hpp"
#include <iomanip>

class   phonebook
{
    private:
        contact cts[8];
        int index;
        int size;
    public:
        phonebook();
        void    add();
        void    search();
        void    exit();
        ~phonebook();

};