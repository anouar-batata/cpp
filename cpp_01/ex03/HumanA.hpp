#include "Weapon.hpp"

class    HumanA
{
    private:
        Weapon &wp1;
        std::string name;
    public:
        HumanA(std::string str,Weapon &wp);
        void    attack();


};