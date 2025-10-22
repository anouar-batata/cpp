#include "easyfind.hpp"
#include <vector>



int main()
{
    std::vector<int> vec;
    for (int i = 0; i < 100; ++i)
        vec.push_back(i * 10);

    try
    {
        std::vector<int>::iterator it = easyfind(vec, 50);
        std::cout << "Found: " << *it << std::endl;
        
        it = easyfind(vec, 60);
        std::cout << "Found: " << *it << std::endl;

        it = easyfind(vec, 151);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}