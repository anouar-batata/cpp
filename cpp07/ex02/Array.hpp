#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>



template <typename T>
class Array 
{
   private:
    T* elements;
    unsigned int size;
    public:
    Array() : elements(NULL), size(0) {}
    Array(unsigned int n) : elements(new T[n]()), size(n) {}
    Array(const Array& other) : elements(new T[other.size]()), size(other.size)
    {
        for (unsigned int i = 0; i < size; ++i) {
            elements[i] = other.elements[i];
        }
    }
    ~Array() {
        delete[] elements;
    }
    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] elements;
            size = other.size;
            elements = new T[size]();
            for (unsigned int i = 0; i < size; ++i) {
                elements[i] = other.elements[i];
            }
        }
        return *this;
    }
    T& operator[](unsigned int index) {
        if (index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        return elements[index];
    }
    const T& operator[](unsigned int index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        return elements[index];
    }
    unsigned int getSize() const {
        return size;
    }
}; 




#endif