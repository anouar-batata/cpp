#include "Serializer.hpp"

int main()
{
    Data a;
    a.id = 10;
    uintptr_t tmp;
    std::cout << &a << std::endl;
    tmp = Serializer::serialize(&a);
    std::cout << tmp << std::endl;
    Data *b = Serializer::deserialize(tmp);
    std::cout << b << std::endl;
}