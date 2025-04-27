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
        ScalarConverter(const ScalarConverter& copy);
        ScalarConverter &operator=(const ScalarConverter &obj);
        ~ScalarConverter();
        static void covert_fn(std::string str);
};

#endif