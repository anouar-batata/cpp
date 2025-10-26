#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>



int str_valid(std::string str);
int  strdigit(std::string str);
void parse_input_file(const std::string& input_file, const std::map<std::string, double>& data_base);
void store_data_base(const std::string& filename, const std::string& input_file);