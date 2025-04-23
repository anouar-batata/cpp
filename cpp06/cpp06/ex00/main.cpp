#include "ScalarConverter.hpp"

int main(int ac, char *av[])
{
    if (ac == 2)
    {
        ScalarConverter::covert_fn(av[1]);
    }
    else
    {
        std::cout << "enter one argument after the excecutable name !" << std::endl;
    }
}