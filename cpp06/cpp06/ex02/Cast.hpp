#ifndef CAST_HPP 
#define CAST_HPP  


#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <cstdlib>
#include <ctime>


Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif 