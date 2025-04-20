#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private :
        std::string target;
    public :
     // Canonical form
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string target);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(ShrubberyCreationForm &obj);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &obj);
    //

    class FormNotSigned : public std::exception
    {
        public:
             const char* what() const throw();
    };

    void execute(Bureaucrat const & executor) const;
};