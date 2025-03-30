#ifndef BRAIN_HPP
#define BRAIN_HPP 

#include <iostream>

class Brain
{
    public:
        Brain();
        Brain(const Brain &obj);
        Brain &operator=(const Brain &obj);
        ~Brain();

    private:
        std::string ideas[100];
};
#endif