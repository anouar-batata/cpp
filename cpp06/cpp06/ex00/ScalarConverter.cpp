#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    //
}

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
    (void)copy;
}

ScalarConverter::~ScalarConverter()
{
    //
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj)
{
    (void)obj;
}


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
            if (i != str.length() - 1 || str[i - 1] == '.')
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

        std::cout << "char: ";
        if (std::isprint(c))
            std::cout << "'" << c << "'" << std::endl;
        else
        std::cout << "Non displayable" << std::endl;

   std::cout << "int: " << i << std::endl;
   std::cout << "float: " << f << "f" << std::endl;
   std::cout << "double: " << d << std::endl;
}

void    convert_and_cast_d_i(std::string str)
{
    // std::cout << std::fixed << std::setprecision(std::numeric_limits<double>::digits10);
    double d;
    float f;
    int i;
    int flag_for_overflow = 0;
    
    // convert to double
    std::cout << std::fixed << std::setprecision(2);
    std::stringstream ss(str);
    ss >> d;
    std::cout << d << std::endl;
    if (ss.fail()) {
        std::cout << "Invalid input\n";
        return;
    }
    //type cast to float !
    f = static_cast<float>(d);
    if (d > 214783647.0 || d < -214783648.0)
        flag_for_overflow = 1;

    if (flag_for_overflow == 1)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std:: cout << "float: " << f << "f" << std::endl; 
        std:: cout << "double: " << d << std::endl; 
    }
    else
    {
        //cast to int
        i = static_cast<int>(d);
        //cast to char
        char c = static_cast<char>(d);
        std::cout << "char: ";
    
        if ((i < 0 || i > 128) || !std::isprint(c))
        {
            if (i < 0 || i > 255)
            std::cout << "impossible"<<  std::endl;
            else
                std::cout << "Non displayable"<<  std::endl;
        }
        else
            std::cout << "'" << c << "'" << std::endl; 
        std::cout << "int: " << i << std::endl;
        std:: cout << "float: " << f << "f" << std::endl; 
        std:: cout << "double: " << d << std::endl;
    }  
}

void    convert_and_cast_f(std::string str)
{
    // std::cout << std::fixed << std::setprecision(std::numeric_limits<double>::digits10);
    double d;
    float f;
    int i;
    int flag_for_overflow = 0;

    if (!str.empty() && str[str.length() - 1] == 'f')
        str = str.substr(0, str.length() - 1);

    // convert to float
    std::stringstream ss(str);
    ss >> f;
    if (ss.fail()) {
        std::cout << "Invalid input\n";
        return;
    }
    //type cast to double !
    d = static_cast<double>(f);
    if (d != 5.99999999)
        std::cout << "hi" << std::endl;
    if (d > 214783647.0 || d < -214783648.0)
        flag_for_overflow = 1;
    // std::cout << std::fixed << std::setprecision(1);

    if (flag_for_overflow == 1)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std:: cout << "float: " << f << "f" << std::endl; 
        std:: cout << "double: " << d << std::endl; 
    }
    else
    {
        //cast to int
        i = static_cast<int>(d);
        //cast to char
        char c = static_cast<char>(d);
        std::cout << "char: ";
        if ((i < 0 || i > 128) || !std::isprint(c))
        {
            std::cout << "Non displayable"<<  std::endl;
        }
        else
            std::cout << "'" << c << "'" << std::endl; 
        std::cout << "int: " << i << std::endl;
        std:: cout << "float: " << f << "f" << std::endl; 
        std:: cout << "double: " << d << std::endl;
    }  
}

void    get_type_and_cast(std::string str)
{
    if (str.find('.') != std::string::npos && str.find('f') != std::string::npos) // float
    {
        convert_and_cast_f(str);
    }
    else if (str.find('.') != std::string::npos) // double
        convert_and_cast_d_i(str);
    else
        convert_and_cast_d_i(str); // int 
}

void ScalarConverter::covert_fn(std::string str)
{
    int flag = 0;
    if (check_the_str(str, &flag))
        convert_to_others_types(flag);
    else
    {
        if (str.length() == 1 && std::isalpha(str[0]))
            convert_the_char(str[0]);
        else
        {
            parse_the_string(str);
            get_type_and_cast(str);
        }
    }
}