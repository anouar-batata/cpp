#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
int check_the_arguments(char **av)
{
    std::string str1 = av[1];
    std::string str2 = av[2];
    std::string str3 = av[3];


    if(str1.empty() || str2.empty() || str3.empty())
        return(1);

    return(0);
    
}

void remplace_the_string(std::string &content, std::string s1, std::string s2, size_t pos)
{
    content.erase(pos, s1.length());
    content.insert(pos, s2);
}

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "incorrect arguments in the input" << std::endl;
        return(1);
    }
    else
    {
        if (check_the_arguments(av) == 1)
        {
            std::cout << "empty string !" << std::endl;
            return 1;
        }

        std::ifstream inputfile(av[1]);
        if(!inputfile)
        {
            std::cout << "cant open the file" << std::endl;
            return 1;
        }
        std::string namefile = av[1];
        std::string outfile = std::string (av[1]) + ".replace";
        std::ofstream outputfile(outfile.c_str());
        if(!outputfile)
        {
            std::cout << "cant open the file" << std::endl;
            return 1;
        }

        std::stringstream buff;
        buff << inputfile.rdbuf();
        std::string content = buff.str();

        size_t pos;
        while (1)
        {
            pos = content.find(av[2]);
            if (pos == std::string::npos)
                break;
            else
                remplace_the_string(content, av[2], av[3], pos);
        }
        outputfile << content;


    }
}