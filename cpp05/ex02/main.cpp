#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"


int main()
{
    try
    {
        Bureaucrat b("b", 6);
        PresidentialPardonForm f1("form");
        f1.besigned(b);
        b.executeForm(f1);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Bureaucrat b1("b1", 50);
        ShrubberyCreationForm f2("form");
        f2.besigned(b1);
        b1.executeForm(f2);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
try
{
    Bureaucrat c("C", 5);
    RobotomyRequestForm f("form");
    f.besigned(c);
    c.executeForm(f);
}
catch(const std::exception& e)
{
    std::cerr << e.what() << '\n';
}


// exemples of a bureaucrat can sign or execut


try
{
    // cant execut
        Bureaucrat b_2("b_2", 20);
        PresidentialPardonForm f1("form");
        f1.besigned(b_2); // valid
        b_2.executeForm(f1);
}
catch(const std::exception& e)
{
    std::cerr << e.what() << '\n';
}


try
{
    // cant sign 
    Bureaucrat b_3("b_3", 150);
    ShrubberyCreationForm f2("form");
    f2.besigned(b_3);
    b_3.executeForm(f2);
}
catch(const std::exception& e)
{
    std::cerr << e.what() << '\n';
}


    

}