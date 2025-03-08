#include <iostream>
class Zombie
{
    private:
        std::string name;
    public:
        void    set_the_name(std::string input);
        std::string get_the_name();
        void announce(void);
         ~Zombie();
};

void randomChump(std::string name);