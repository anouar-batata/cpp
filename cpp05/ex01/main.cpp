#include "Bureaucrat.hpp"
#include "Form.hpp"


int main()
{

    try
    {
        Form f("from", 50, 50);
        Bureaucrat  A("A", 50);
        std::cout << f << std::endl;
        A.signForm(f);
        std::cout << f << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Bureaucrat B("B", 100);
        Form f1("form1", 50, 10);
        std::cout << f1 << std::endl;
        B.signForm(f1);
    }
    catch(const std::exception& e)
    {
        std::cout << "this line will be not excecuted" << std::endl;

        std::cerr << e.what() << '\n';
    }
    
    try
    {
        Form f2("f2", 1000000, 10000000);
        Bureaucrat C("C", 400000);
        C.signForm(f2);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    // try
    // {
    //     Bureaucrat obj1("A", 150);
    //     std::cout << obj1 << std::endl;
    //     obj1.grade_decrement();

    // }
    // catch(const std::exception &e)
    // {
    //     std::cerr << e.what() << std::endl;
    // }

    // try
    // {
    //     Bureaucrat obj2("B", 2);
    //     std::cout << obj2 << std::endl;
    //     obj2.grade_increment();
    //     std::cout << obj2.get_grade() << std::endl;
    //     obj2.grade_increment();
    //     std::cout << "this line will be not executed" << std::endl;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    // // successfully Bureaucrat
    // try
    // {
    //     Bureaucrat obj3("C", 50);
    //     std::cout << obj3 << std::endl;
    //     obj3.grade_decrement();
    //     std::cout << "new grade : " << obj3.get_grade() << std::endl;

    // }
    // // there are no exception !
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    

}