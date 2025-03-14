#include "Weapon.hpp"

class    HumanB
{
    private:
        Weapon *wp2;
        std::string name;
    public:
        HumanB(std::string str);
        void    attack();
        void    setWeapon(Weapon &input);


};