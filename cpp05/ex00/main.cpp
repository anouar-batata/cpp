#include "Bureaucrat.hpp"


int main()
{
    try
    {
        Bureaucrat obj1("A", 150);
        std::cout << obj1 << std::endl;
        obj1.grade_decrement();

    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Bureaucrat obj2("B", 2);
        std::cout << obj2 << std::endl;
        obj2.grade_increment();
        std::cout << obj2.get_grade() << std::endl;
        obj2.grade_increment();
        std::cout << "this line will be not executed" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    // successfully Bureaucrat

    try
    {
        Bureaucrat obj3("C", 50);
        std::cout << obj3 << std::endl;
        obj3.grade_decrement();
        std::cout << "new grade : " << obj3.get_grade() << std::endl;

    }
    // there are no exception !
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

}