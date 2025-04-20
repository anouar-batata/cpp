#ifndef FORM_HPP 
#define FORM_HPP


#include "Bureaucrat.hpp"


class Bureaucrat;


class Form
{
    private :
        const std::string name;
        bool signed_index;
        const int grade;
        const int grade_req;
    public :
        // Canonical form
        Form();
        ~Form();
        Form(const Form &obj);
        Form(const std::string name,const int grade, const int grade_req);
        Form &operator=(const Form &obj);
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
        bool get_signed_index() const;
        int get_grade() const;
        int get_grade_req() const;
        //

        void besigned(Bureaucrat &obj);



};
std::ostream& operator<<(std::ostream &os, const Form &b);


#endif