#include "BitcoinExchange.hpp"

int str_valid(std::string str)
{
    int count = 0;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] == '-')
            count++;
        if ( (str[i] < '0' || str[i] > '9') && str[i] != '-')
            return 0;
    }
    if (count != 2)
        return 0;
    return 1;
}

int  strdigit(std::string str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return 0;
    }
    return 1;
}

int second_parse(std::string line, size_t pipe_pos)
{
    std::string input = line.substr(pipe_pos + 1); // 2020-12-01 |

    if (input.length() < 2)
    {
        std::cerr << "ERROR: bad input => " << line << std::endl;
        return 0;
    }
    if (input[0] != ' ')
    {
        std::cerr << "ERROR: bad input => " << line << std::endl;
        return 0;
    }
    input = input.substr(1); //trim space
    int count_dot = 0;
    
    if (input[0] == '.' || input[input.length() - 1] == '.')
    {
        std::cerr << "ERROR: bad input => " << line << std::endl;
        return 0;
    }
    for (size_t i = 0; i < input.length(); i++)
    {

        if (input[i] == '.')
            count_dot++;
        if ( (input[i] < '0' || input[i] > '9') && input[i] != '.' && input[i] != '-')
        {
            std::cerr << "ERROR: bad input => " << line << std::endl;
            return 0;
        }
        if (input[i] == '-' && i != 0)
        {
            std::cerr << "ERROR: bad input => " << line << std::endl;
            return 0;
        }
    }
    if (count_dot > 1)
    {
        std::cerr << "ERROR: bad input => " << line << std::endl;
        return 0;
    }
    double value = atof(input.c_str());
    if (value <0 || value > 1000)
    {
        if (value < 0)
            std::cerr << "ERROR: not a positive number."<< std::endl;
        else
            std::cerr << "ERROR: too large number." << std::endl;
        return 0;
    }
    return 1;
}


void parse_input_file(const std::string& input_file, const std::map<std::string, double>& data_base)
{
    std::ifstream file(input_file.c_str());
    if (!file.is_open())
    {
        std::cerr << "ERROR: Could not open file " << input_file << std::endl;
        return;
    }
    std::string input;
    std::string line ;
    std::getline(file, input);
    if ( input != "date | value")
    {
        std::cerr << "ERROR: Invalid header in input file" << std::endl;
        file.close();
        return;
    }
    while (std::getline(file, line))
    {
        size_t pipe_pos = line.find('|');
        if (pipe_pos == std::string::npos || pipe_pos != 11)
        {
            std::cerr << "ERROR: bad input => " << line << std::endl;
            continue;
        }
        if (line[10] != ' ')
        {
            std::cerr << "ERROR: bad input => " << line.substr(0, 10) << std::endl;
            continue;
        }
        if (!str_valid(line.substr(0, 10)))
        {
            std::cerr << "ERROR: bad input => " << line.substr(0, 10) << std::endl;
            continue;
        }
        std::string input = line.substr(0, 10);
        size_t pos1;
        size_t pos2;

        pos1 = input.find('-');
        pos2 = input.find('-', pos1 + 1);
        std::string year = input.substr(0, pos1);
        std::string month = input.substr(pos1 + 1, pos2 - pos1 - 1);
        std::string day = input.substr(pos2 + 1);
        if (!strdigit(year) || !strdigit(month) || !strdigit(day) ||
            year.length() != 4 || month.length() != 2 || day.length() != 2)
        {
            std::cerr << "ERROR: bad input => " << input << std::endl;
            continue;
        }
        int month_i = atoi(month.c_str());
        int day_i = atoi(day.c_str());
        if (month_i < 1 || month_i > 12 || day_i < 1 || day_i > 31)
        {
            std::cerr << "ERROR: bad input => " << input << std::endl;
            continue; 
        }
        //second part
        if (!second_parse(line, pipe_pos))
            continue;
        double value = atof(line.substr(pipe_pos + 2).c_str());
        std::map<std::string, double>::const_iterator it = data_base.lower_bound(input);
        if (it != data_base.end() && it->first == input)
        {
            std::cout << input << " => " << value << " = " << value * it->second << std::endl;
        }
        else if (it != data_base.begin())
        {
            --it;
            std::cout << input << " => " << value << " = " << value * it->second << std::endl;
        }
        else
        {
            std::cerr << "ERROR: No data available for date " << input << std::endl;
        }
    }
    file.close();
}

void store_data_base(const std::string& filename, const std::string& input_file)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "ERROR: Could not open file " << filename << std::endl;
        return;
    }
    std::map<std::string, double> data_base;
    std::string line;
    while (std::getline(file, line))
    {
        size_t comma_pos = line.find(',');
        if (comma_pos != std::string::npos)
        {
            std::string date = line.substr(0, comma_pos);
            double value = atof(line.substr(comma_pos + 1).c_str());
            data_base[date] = value;
        }
    }
    file.close();

    parse_input_file(input_file, data_base);

}