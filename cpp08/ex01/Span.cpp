#include "Span.hpp"
#include <limits.h> // for INT_MAX



Span::Span(unsigned int n) : max_int(n) {}

Span::Span(const Span& other) : max_int(other.max_int), numbers(other.numbers)
{

}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        max_int = other.max_int;
        numbers = other.numbers;
    }
    return *this;
}

Span::~Span()
{

}

void Span::addNumber(int number)
{
    if (numbers.size() >= max_int)
        throw std::runtime_error("Cannot add more numbers.");
    numbers.push_back(number);
}

int Span::shortestSpan() const
{
    if (numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to find a short span!");

    std::vector<int> sorted_numbers = numbers;
    std::sort(sorted_numbers.begin(), sorted_numbers.end());
    int min_span = INT_MAX;
    for (size_t i = 1; i < sorted_numbers.size(); ++i)
    {
        int span = sorted_numbers[i] - sorted_numbers[i - 1];
        if (span < min_span)
            min_span = span;
    }
    return min_span;
}

int Span::longestSpan() const
{
    if (numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to find a long span!");
    std::vector<int> sorted_numbers = numbers;
    std::sort(sorted_numbers.begin(), sorted_numbers.end());
    std::vector<int>::iterator min_it = sorted_numbers.begin();
    std::vector<int>::iterator max_it = sorted_numbers.end() - 1;

    // std::cout << "Min: " << *min_it << ", Max: " << *(max_it) << std::endl;

    return (*max_it - *min_it);

}
