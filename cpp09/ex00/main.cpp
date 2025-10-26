#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "ERROR : entre the right number of arguments" << std::endl;
        return 1;
    }

    store_data_base("data.csv", argv[1]);
    
}