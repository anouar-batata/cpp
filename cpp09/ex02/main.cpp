#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cerr << "not enough arguments" << std::endl;
        return 1;
    }
    parse_input(&argv[1]);
    std::vector<int> numbers;
    std::deque<int> numbers_dq;
    for (int i = 1; i < argc; i++)
    {
        numbers.push_back(atoi(argv[i]));
        numbers_dq.push_back(atoi(argv[i]));
    }
    
    if (is_sorted(numbers))
    {
        std::cout << "The sequence is already sorted." << std::endl;
        exit(1);
    }
    std::cout << "Before: ";
    for (size_t i = 0; i < numbers.size(); i++)
        std::cout << numbers[i] << " ";
    std::cout << std::endl;
    clock_t start = clock();
    numbers = pairing(numbers, 1);
    clock_t end = clock();
    double time_vec = double(end - start) / CLOCKS_PER_SEC * 1000000;
    start = clock();
    numbers_dq = pairing_dq(numbers_dq, 1);
    end = clock();
    double time_dq = double(end - start) / CLOCKS_PER_SEC * 1000000;
    std::cout << "After: ";
    for (size_t i = 0; i < numbers.size(); i++)
        std::cout << numbers[i] << " ";
    std::cout << std::endl;
    
    std::cout << "Time to process a range of " << numbers.size() << " elements with std::vector : " << time_vec << " us" << std::endl;
    std::cout << "Time to process a range of " << numbers.size() << " elements with std::deque : " << time_dq << " us" << std::endl;
    return 0;
}
