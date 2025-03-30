#include "Animal.hpp"
#include "brain.hpp"

class Cat : public Animal
{
    public:
        Cat();
        Cat(const Cat &obj);
        Cat &operator=(const Cat &obj);
        ~Cat();
        void makeSound() const;

    private:
        Brain *brain;
};