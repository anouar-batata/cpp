#ifndef SCALARCONVERTER_HPP 
#define SCALARCONVERTER_HPP 

#include <iostream>
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <sstream> 

class ScalarConverter
{
    private :
        ScalarConverter();
        
    public:
        static void covert_fn(std::string str);
};

#endif