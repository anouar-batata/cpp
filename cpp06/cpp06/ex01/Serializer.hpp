#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP


#include <iostream>
#include "Data.hpp"
#include <stdint.h> 


class Serializer
{
    private:
        Serializer();
    public:
    Serializer(const Serializer &obj);
    Serializer &operator=(const Serializer &obj);
    ~Serializer();
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw); 
};

#endif