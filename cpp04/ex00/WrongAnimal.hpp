#ifndef WrongANIMAL_HPP
#define WrongANIMAL_HPP  


#include <iostream>

class WrongAnimal
{
    public:
    WrongAnimal();
        ~WrongAnimal();
        WrongAnimal(const WrongAnimal &obj);
        WrongAnimal &operator=(const WrongAnimal &obj);
         void makeSound() const;
        std::string getType() const;

    protected:
        std::string type;
};


#endif