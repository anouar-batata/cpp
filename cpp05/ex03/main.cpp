#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"


int main()
{
    AForm *f = NULL;
    try
    {
        Intern  i;
        Bureaucrat b("b", 25);
        f = i.makeForm("shrubbery creation", "hello");
        f->besigned(b);
        f->execute(b);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    delete f;

    AForm *f1 = NULL;

    try
    {
        Intern  i;
        Bureaucrat b("b", 25);
        f1 = i.makeForm("robotomy request", "hello");
        f1->besigned(b);
        f1->execute(b);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    AForm *f2 = NULL;
    try
    {
        Intern  i;
        Bureaucrat b("b", 5);
        f2 = i.makeForm("presidential pardon", "hello");
        f2->besigned(b);
        f2->execute(b);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}