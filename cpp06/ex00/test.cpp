#include <iostream>
#include <string>


int main()
{
    std::string s = "2147483647";
    double n = 0;
    n = std::stof(s);
    std::cout << n << std::endl;
}