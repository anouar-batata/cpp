#include "AForm.hpp"
#include "Bureaucrat.hpp"


AForm::AForm() : name("default"), signFlag(false), grade_to_sign(150), grade_to_exce(150)
{
    std::cout << "default constructor called" << std::endl;
}

AForm::AForm(const AForm &obj) : name(obj.name), signFlag(obj.signFlag), grade_to_sign(obj.grade_to_sign), grade_to_exce(obj.grade_to_exce)
{
    std::cout << "copy constructor called" << std::endl;
}

AForm::AForm(const std::string name,const int grade, const int grade_req) : name(name),grade_to_sign(grade), grade_to_exce(grade_req)
{
    
    std::cout << "default constructor called" << std::endl;
    this->signFlag = false;
    if (grade > 150 || grade_req > 150)
    throw GradeTooLowException();
    if (grade < 1 || grade_req < 1)
    throw GradeTooHighException();
}

AForm &AForm::operator=(const AForm &obj)
{
    std::cout << "copy assignement called" << std::endl;

    this->signFlag = obj.signFlag;
    return(*this);
}




const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade is low!";
}


std::string AForm::get_the_name() const
{
    return(name);
}

bool AForm::get_signFlag() const
{
    return(signFlag);
}

int AForm::get_grade_to_sign() const
{
    return(grade_to_sign);
}

int AForm::get_grade_to_exce() const
{
    return(grade_to_exce);
}

void AForm::besigned(Bureaucrat &obj)
{
    if (this->get_grade_to_sign() >= obj.get_grade())
    {
        signFlag = true;
    }
    else
    {
        throw GradeTooLowException();
    }
}

std::ostream &operator<<(std::ostream &os, const AForm &b)
{
    os << b.get_the_name() << ", form grade to signed " << b.get_grade_to_sign()
        << ", form grade to excecuted " << b.get_grade_to_exce();
    if (b.get_signFlag())
    {
        os << " and the form signed !";
    }
    return os;
}


AForm::~AForm()
{
    std::cout << "default destructor called" << std ::endl;
}