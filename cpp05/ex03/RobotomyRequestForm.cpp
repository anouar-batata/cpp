#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : target("default"), AForm("Robot", 72, 45)
{
    std::cout << "default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : target(target), AForm("Robot", 72, 45)
{
    std::cout << "default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &obj)
{
    *this = obj;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
    this->target = obj.target;
    return(*this);
}

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!this->get_signFlag())
        throw FormNotSigned();

    if (executor.get_grade() > this->get_grade_to_exce())
        throw GradeTooLowException();
    std::cout << "Makes some drilling noises !" << std::endl;
    std::srand(std::time(0));
    if (std::rand() % 2)
    {
        std::cout << target << " has been robotomized successfully" << std::endl;
    }
    else
        std::cout << " the robotomy failed." << std::endl;
}


const char *RobotomyRequestForm::FormNotSigned::what() const throw()
{
    return("the form not signed !");
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "default destructor called" << std::endl;
}