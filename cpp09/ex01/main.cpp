#include <iostream>
#include <cstdlib>
#include <stack>


void parse_inpute(std::string input)
{
    if (input.empty())
    {
        std::cerr << "ERROR" << std::endl;
        exit(1);
    }
    if (std::isspace(input[0]))
    {
        std::cerr << "ERROR" << std::endl;
        exit(1);
    }
    int flag_for_space = 1;
    for (size_t i = 0; i < input.length(); i++)
    {
        if (!std::isdigit(input[i]) && input[i] != '+' && input[i] != '-' && input[i] != '*' && input[i] != '/' &&  !std::isspace(input[i]))
        {
            std::cerr << "ERROR" << std::endl;
            exit(1);
        }
        else if (std::isdigit(input[i]) || input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
        {
            if (flag_for_space != 1)
            {
                std::cerr << "ERROR" << std::endl;
                exit(1);
            }
            flag_for_space--;
        }
        else if (std::isspace(input[i]))
        {
            flag_for_space++;
            if (flag_for_space > 1)
            {
                std::cerr << "ERROR" << std::endl;
                exit(1);
            }
        }

    }
}

void    ft_rpn(std::string input)
{
    std::stack<double> stack;

    for (size_t i = 0; i < input.length(); i++)
    {
        if (std::isspace(input[i]))
            continue;
        else if (std::isdigit(input[i]))
        {
            double a = atof(&input[i]);
            stack.push(a);
        }
        else
        {
            if (stack.size() < 2)
            {
                std::cerr << "ERROR" << std::endl;
                exit(1);
            }
            else
            {
                double t = 0;
                double a = stack.top(); stack.pop();
                double b = stack.top(); stack.pop();
                if (input[i] == '+')
                {
                    t = b + a;
                    stack.push(t);
                }
                else if (input[i] == '-')
                {
                    t = b - a;
                    stack.push(t);
                }
                else if (input[i] == '*')
                {
                    t = b * a;
                    stack.push(t);
                }
                else
                {
                    t = b / a;
                    stack.push(t);
                }
                
            }
        }
    }
    if (stack.size() != 1)
    {
        std::cerr << "ERROR" << std::endl;
        exit(1);
    }
    std::cout << stack.top() << std::endl;
    exit(0);
}

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "ERROR : entre the right number of arguments" << std::endl;
        return 1;
    }
    parse_inpute(argv[1]);
    ft_rpn(argv[1]);
}