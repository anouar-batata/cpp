#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "default constuctor called" << std::endl;
}

Intern::Intern(const Intern &obj)
{
    std::cout << "copy constructor called" << std::endl;
    (void)obj;
}
Intern &Intern::operator=(const Intern &obj)
{
    std::cout << "copy assignment operator called" << std::endl;
    (void) obj;
    return(*this);
}

 AForm *Intern::createShrubberyForm(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyForm(std::string target)
{
    return new RobotomyRequestForm(target);
}
AForm *Intern::createPresidentialForm(std::string target)
{
    return new PresidentialPardonForm(target);
}


AForm *Intern::makeForm(std::string name_of_form, std::string target)
{
    std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* (Intern::*formConstructors[3])(std::string) = {&Intern::createShrubberyForm, &Intern::createRobotomyForm, &Intern::createPresidentialForm};
    
    for (int i = 0; i < 3; i++)
    {
        if (name_of_form == names[i])
        {
            std::cout << "Intern creates a " << name_of_form << std::endl;
            return (this->*formConstructors[i])(target);
        }
    }
    throw InvalidForm();
};

const char* Intern::InvalidForm::what() const throw()
{
    return "cant create a form , name of form invalid !";
}


Intern::~Intern()
{
    std::cout << "default destructor called" << std::endl;
}