#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

PresidentialPardonForm::PresidentialPardonForm() : AForm("Robot", 25, 5) ,target("default")
{
    std::cout << "default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("Robot", 25, 5) ,target(target)
{
    std::cout << "default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &obj) : AForm("Robot", 25, 5)
{
    *this = obj;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
{
    this->target = obj.target;
    return(*this);
}

void    PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!this->get_signFlag())
        throw FormNotSigned();

    if (executor.get_grade() > this->get_grade_to_exce())
        throw GradeTooLowException();
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;

}


const char *PresidentialPardonForm::FormNotSigned::what() const throw()
{
    return("the form not signed !");
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "default destructor called" << std::endl;
}