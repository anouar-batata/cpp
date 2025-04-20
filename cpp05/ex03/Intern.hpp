#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {

    private:
    AForm* createShrubberyForm(std::string target);
    AForm* createRobotomyForm(std::string target);
    AForm* createPresidentialForm(std::string target);
    
    public:
        Intern();
        ~Intern();
        Intern(const Intern &obj);
        Intern &operator=(const Intern &obj);

        class InvalidForm : public std::exception
        {
            public:
                const char* what() const throw();
        };

        AForm* makeForm(std::string name_of_form, std::string target);
};

#endif