#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private :
        std::string target;
    public :
     // Canonical form
     RobotomyRequestForm();
     RobotomyRequestForm(const std::string target);
    ~RobotomyRequestForm();
    RobotomyRequestForm(RobotomyRequestForm &obj);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &obj);
    //

    class FormNotSigned : public std::exception
    {
        public:
             const char* what() const throw();
    };

    void execute(Bureaucrat const & executor) const;
};