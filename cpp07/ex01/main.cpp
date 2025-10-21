#include "iter.hpp"


void    ft_print(int &x)
{
    std::cout << x << std::endl;
}

void ft_changeChar(char &c)
{
    c = c + 1;
}

void ft_printChar(char &c)
{
    std::cout << c << std::endl;
}
int main()
{
    int array[] = {1, 2, 3, 4, 5};
    size_t length = 5;
    iter(array, length, ft_print);


    char array2[] = {'a', 'b', 'c', 'd', 'e'};
    size_t length2 = 5;
    for (size_t i = 0; i < length2; i++)
    {
        std::cout << array2[i] << std::endl;
    }
    return 0;

}