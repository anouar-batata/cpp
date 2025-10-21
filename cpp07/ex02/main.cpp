#include "Array.hpp"

int main() {
    Array<int> intArray(5);
    for (unsigned int i = 0; i < intArray.getSize(); ++i) {
        intArray[i] = i * 10;
    }
    for (unsigned int i = 0; i < intArray.getSize(); ++i) {
        std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
    }

    Array<std::string> strArray(3);
    strArray[0] = "Hello";
    strArray[1] = "World";
    strArray[2] = "!";
    for (unsigned int i = 0; i < strArray.getSize(); ++i) {
        std::cout << "strArray[" << i << "] = " << strArray[i] << std::endl;
    }

    try {
        std::cout << intArray[10] << std::endl; // This should throw an exception
    } catch (const std::out_of_range& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

