#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    // Create an array of Animal pointers (half Dog, half Cat)
    const int size = 10;
    Animal* animals[size];

    // Fill the array with Dog and Cat objects
    for (int i = 0; i < size / 2; ++i) {
        animals[i] = new Dog();  // First half with Dog objects
    }
    for (int i = size / 2; i < size; ++i) {
        animals[i] = new Cat();  // Second half with Cat objects
    }
   

    for (int i = 0; i < size; ++i) {
        delete animals[i];  // Destructor for each Dog and Cat called as Animal
    }


    Dog basic;
    {
    Dog tmp = basic;
    }

    return 0;
}