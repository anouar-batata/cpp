#ifndef AFORM_HPP 
#define AFORM_HPP
#include "Bureaucrat.hpp"
#include <fstream>


class Bureaucrat;


class AForm
{
    private :
        const std::string name;
        bool signFlag;
        const int grade_to_sign;
        const int grade_to_exce;
    public :
        // Canonical form
        AForm();
        virtual ~AForm();
        AForm(const AForm &obj);
        AForm(const std::string name,const int grade_to_sign, const int grade_t_exce);
        AForm &operator=(const AForm &obj);
        //


        class GradeTooHighException : public std::exception
        {
            public:
                 const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                 const char* what() const throw();
        };

        //getters
        std::string get_the_name() const;
        bool get_signFlag() const;
        int get_grade_to_sign() const;
        int get_grade_to_exce() const;
        //

        void besigned(Bureaucrat &obj);
        virtual void execute(Bureaucrat const & executor) const = 0;



};

std::ostream& operator<<(std::ostream &os, const AForm &b);


#endif