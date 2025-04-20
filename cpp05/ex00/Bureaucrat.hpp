#include <iostream>

class Bureaucrat
{
    private:
        const std::string name;
        int grade;

    public:


        Bureaucrat();
        Bureaucrat(const Bureaucrat &obj);
        Bureaucrat(const std::string name, int grade);
        Bureaucrat &operator=(const Bureaucrat &obj);
        ~Bureaucrat();

        int get_grade() const;
        std::string get_the_name() const;
        
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

        void grade_increment();
        void grade_decrement();

};

std::ostream& operator<<(std::ostream &os, const Bureaucrat &b);