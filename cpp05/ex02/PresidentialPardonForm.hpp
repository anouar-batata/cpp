#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private :
        std::string target;
    public :
     // Canonical form
     PresidentialPardonForm();
     PresidentialPardonForm(const std::string target);
    ~PresidentialPardonForm();
    PresidentialPardonForm(PresidentialPardonForm &obj);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &obj);
    //

    class FormNotSigned : public std::exception
    {
        public:
             const char* what() const throw();
    };

    void execute(Bureaucrat const & executor) const;
};