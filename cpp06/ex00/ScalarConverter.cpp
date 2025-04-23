#include "ScalarConverter.hpp"


void errro_msg()
{
    std::cout << "parce error" << std::endl;
    exit(1);
}

int parse_the_string(std::string str)
{
    size_t i = 0;
    int _flag = 0;
    
    while ( i < str.length())
    {
        if (std::isdigit(str[i]))
            i++;
        else if (std::isalpha(str[i]) && i != 0 && str[i] == 'f')
        {
            if (i != str.length() - 1)
                errro_msg();
            return(0);
        }
        else if (str[i] == '.' || str[i] == '+' || str[i] == '-')
        {
            if (_flag == 0)
            {
                if (str[i] == '+' ||str[i] == '-')
                {
                    if (i != 0)
                        errro_msg();
                    i++;
                }
                else
                {
                    if (i == 0 || i == str.length() - 1)
                        errro_msg();
                    _flag = 1;
                    i++;
                }
            }
            else
                errro_msg();
        }
        else
            errro_msg();
    }
        return(1);
}


int check_the_str(std::string str, int *flag)
{
    if (str == "-inf" || str == "-inff")
    {
        *flag = 1;
        return(*flag);
    }
    else if (str == "+inf" || str == "+inff")
    {
        *flag = 2;
        return(*flag);
    }
    else if (str == "nan" || str == "nanf")
    {
        *flag = 3;
        return(*flag);
    }
    else
        return(0);
}


void     convert_to_others_types(int flag)
{
    if (flag == 1)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
    else if ( flag == 2)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
}

void    convert_the_char(char c)
{
    std::cout << std::fixed << std::setprecision(1);
    int i = static_cast<int>(c);
    float f = static_cast<float>(c);
    double d = static_cast<double>(c);

    if (std::isdigit(c))
    {
        std::cout << "char: Non displayable" << std::endl;
    }
    else
    {
        std::cout << "char: ";
        if (std::isprint(c))
            std::cout << "'" << c << "'" << std::endl;
        else
        std::cout << "Non displayable" << std::endl;
    }
   std::cout << "int: " << i << std::endl;
   std::cout << "float: " << f << "f" << std::endl;
   std::cout << "double: " << d << std::endl;
}

void    convert_the_float(std::string str)
{
    double d;
    float f;
    int i;
    int flag_for_overflow = 0;


    if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
        flag_for_overflow = 1;
    std::cout << "char: ";
    // if (std::)
    
}

void    get_type_and_cast(std::string str)
{
    if (str.find('.') != std::string::npos && str.find('f') != std::string::npos)
        convert_the_float(str);
}

void ScalarConverter::covert_fn(std::string str)
{
    int flag = 0;
    if (check_the_str(str, &flag))
        convert_to_others_types(flag);
    else
    {
        if (str.length() == 1)
            convert_the_char(str[0]);
        else
        {
            parse_the_string(str);
            get_type_and_cast(str);
        }
    }
}