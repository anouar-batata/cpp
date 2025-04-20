#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("defautlt"), grade(150)
{
    std::cout << "default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
{
    this->grade = obj.grade;
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
    if (this != &obj)
    {
        this->grade = obj.grade;
    }
    return(*this);
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade)
{
    std::cout << "default constructor called" << std::endl;
    if (this->grade < 1)
        throw GradeTooHighException();
    if (this->grade > 150)
        throw GradeTooLowException();
}



int Bureaucrat::get_grade() const
{
    return(grade);
}

std::string Bureaucrat::get_the_name() const
{
    return(name);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    
    return "Grade is too high than 1!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is low than 150!";
}

void    Bureaucrat::grade_increment()
{
    grade--;
    if (grade == 0)
        throw GradeTooHighException();
}

void    Bureaucrat::grade_decrement()
{
    grade++;
    if (grade == 151)
        throw GradeTooLowException();
}

void Bureaucrat::signForm(Form &form)
{
    try
    {
        form.besigned(*this);
        std::cout << name << " signed " << form.get_the_name() << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << name << " couldn’t sign " << form.get_the_name() << " because " <<  e.what() << '\n';
    }
    
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b) 
{
    os << b.get_the_name() << ", bureaucrat grade " << b.get_grade();
    return os;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "default destuctor called" << std::endl;
}
