

#include <iostream>


int main()
{
    std::string str;
    str =  "HI THIS IS BRAIN";
    std::string *stringPTR;
    std::string &stringREF = str;

    stringPTR = &str;

    std::cout << "  The memory address of the string : " << &str << std::endl;
    std::cout << "  The memory address of stringPTR : " << stringPTR << std::endl;
    std::cout << "  The memory address of stringREF : " << &stringREF << std::endl;



    std::cout << "  The value of the string : " << str << std::endl;
    std::cout << "  The value of the stringPTR : " << *stringPTR << std::endl;
    std::cout << "  The value of the stringREF : " << stringREF << std::endl;



}