#ifndef Weapon_HPP
# define Weapon_HPP

#include <iostream>


class   Weapon
{
    private:
        std::string type;
    public:
        Weapon(std::string str);
        std::string &getType();
        void setType(std::string input);


};

#endif