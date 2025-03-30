#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    // Animal k; abstract class

    Animal *i = new Dog();
    Animal *j = new Cat();

    delete i;
    delete j;


}