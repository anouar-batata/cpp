#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : target("default"), AForm("shrubbery", 145, 137)
{
    std::cout << "default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : target(target), AForm("shrubbery", 145, 137)
{
    std::cout << "default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &obj)
{
    *this = obj;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
    this->target = obj.target;
    return(*this);
}

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (!this->get_signFlag())
        throw FormNotSigned();

    if (executor.get_grade() > this->get_grade_to_exce())
        throw GradeTooLowException();
    std::string str = target + "_shrubbery";
    std::ofstream file(str.c_str()); // just to return const char *
    if (file)
    {
        file << "       ###\n";
        file << "      #o###\n";
        file << "    #####o###\n";
        file << "   #o#\\#|#/###\n";
        file << "    ###\\|/#o#\n";
        file << "     # }|{  #\n";
        file << "       }|{\n";
        file << "       TREE\n       ";


        file.close();
    }
    else
    {
        std::cout << "cant open the file !" << std::endl;
    }

}


const char *ShrubberyCreationForm::FormNotSigned::what() const throw()
{
    return("the form not signed !");
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "default destructor called" << std::endl;
}