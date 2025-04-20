#include "Form.hpp"
#include "Bureaucrat.hpp"


Form::Form() : name("default"), signed_index(false), grade(150), grade_req(150)
{
    std::cout << "default constructor called" << std::endl;
}

Form::Form(const Form &obj) : name(obj.name), signed_index(obj.signed_index), grade(obj.grade), grade_req(obj.grade_req)
{
    std::cout << "copy constructor called" << std::endl;
}

Form::Form(const std::string name,const int grade, const int grade_req) : name(name),grade(grade), grade_req(grade_req)
{

    std::cout << "default constructor called" << std::endl;
    this->signed_index = false;
    if (grade > 150 || grade_req > 150)
    throw GradeTooLowException();
    if (grade < 1 || grade_req < 1)
    throw GradeTooHighException();
}

Form &Form::operator=(const Form &obj)
{
    std::cout << "copy assignement called" << std::endl;

    this->signed_index = obj.signed_index;
    return(*this);
}




const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade is low!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade is too high!";
}


std::string Form::get_the_name() const
{
    return(name);
}

bool Form::get_signed_index() const
{
    return(signed_index);
}

int Form::get_grade() const
{
    return(grade);
}

int Form::get_grade_req() const
{
    return(grade_req);
}

void Form::besigned(Bureaucrat &obj)
{
    if (this->get_grade() >= obj.get_grade())
    {
        signed_index = true;
    }
    else
        throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const Form &b)
{
    os << b.get_the_name() << ", form grade to signed " << b.get_grade()
        << ", form grade to excecuted " << b.get_grade_req();
    if (b.get_signed_index())
    {
        os << " and the form signed !";
    }
    return os;
}


Form::~Form()
{
    std::cout << "default destructor called" << std ::endl;
}