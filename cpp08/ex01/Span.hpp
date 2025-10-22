#ifndef SPAN_HPP
#define SPAN_HPP


#include "iostream"
#include "vector"
#include <algorithm> // for std::sort


class Span {

    private:
    unsigned int max_int;
    std::vector<int> numbers;

   public:
    Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int number);
    int shortestSpan() const;
    int longestSpan() const;
};

#endif