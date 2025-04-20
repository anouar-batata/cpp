#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"


int main()
{
    AForm *f;
    try
    {
        Intern  i;
        Bureaucrat b("b", 25);
        f = i.makeForm("robotomy request", "target");
        f->besigned(b);
        f->execute(b);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    delete f;


    

}