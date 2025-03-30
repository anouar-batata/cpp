#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    // exemple of polymorphism


     Animal* meta = new Animal();
   Animal* j = new Dog();
     Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    delete j;
    delete i;
    delete meta;
return 0;

//a small exemple when we use wrong animal :


// WrongAnimal*k = new WrongCat();
// k->makeSound();
// delete k;
}
