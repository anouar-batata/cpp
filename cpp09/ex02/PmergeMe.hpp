#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

bool is_sorted(std::vector<int> &numbers);
void parse_input(char **argv);
std::vector<int> sort_algo(std::vector<int> &numbers, int level);
std::vector<int> pairing(std::vector<int> &numbers, int level);
std::deque<int> sort_algo_dq(std::deque<int> &numbers, int level);
std::deque<int> pairing_dq(std::deque<int> &numbers, int level);
