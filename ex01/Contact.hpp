#include <iostream>
#include <cstdlib>

class contact
{
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;

    public:
        contact();
        std::string get_first_name();
        std::string get_last_name();
        std::string get_nickname();
        std::string get_phone_number();
        std::string get_darkest_secret();
        void    set_first_name(std::string input);
        void    set_last_name(std::string input);
        void    set_nickname(std::string input);
        void    set_phone_number(std::string input);
        void    set_darkest_secret(std::string input);
        ~contact();
};