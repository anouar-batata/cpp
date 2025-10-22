#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>


template<typename T>
class MutantStack : public std::stack<T> // std::stack<T, std::deque<T> >
{
    public:
        typedef typename std::deque<T>::iterator        it;
        typedef typename std::deque<T>::const_iterator  const_it;

        //ORTHDX
        MutantStack() {}
        ~MutantStack() {}
        MutantStack(const MutantStack &stack)
        {
            *this = stack;
        }
        MutantStack &operator=(const MutantStack &stack)
        {
            std::stack<T>::operator=(stack); //using the assign op of the base c;ass
            return (*this);
        }
        
        it begin() {
            return (this->c.begin()); 
        }
        it end()
        { 
            return (this->c.end()); 
        } 



        const_it begin() const {
            return (this->c.begin());
        }

        const_it end() const {
            return (this->c.end());
        }

};

#endif