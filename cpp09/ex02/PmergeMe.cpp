#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

bool is_sorted(std::vector<int> &numbers)
{
    for (size_t i = 0; i < numbers.size() - 1; i++)
    {
        if (numbers[i] > numbers[i + 1])
            return false;
    }
    return true;
}

int jacobstal_generator(int n)
{
    //1  3 5  11  21  43 ...
    if (n == 0 || n == 1)
        return 1;
    return  jacobstal_generator(n - 1) + 2 * jacobstal_generator(n - 2);
}
void parse_input(char **argv)
{
    int i = 0;
    while (argv && argv[i])
    {
        std::string input = argv[i];
        for (size_t j = 0; j < input.length(); j++)
        {
            if (!std::isdigit(input[j]))
            {
                std::cerr << "Error" << std::endl;
                exit(1);
            }
        }
        i++;
    }
    
}

std::vector<int> generate_jacob_sizes(int limit)
{

    //1 3 7 15 31 ...
    //2 ^ (k + 1) - 1
    std::vector<int> jacobsthal_numbers;
    int previous = 1, current = 3;
    
    jacobsthal_numbers.push_back(previous);
    if (current <= limit) {
        jacobsthal_numbers.push_back(current);
    }
    while (current <= limit) {
        int next = 2 * current + 1;
        jacobsthal_numbers.push_back(next);
        previous = current;
        current = next;
    }
    return jacobsthal_numbers;
}


std::vector<int> sort_algo(std::vector<int> &numbers, int level)
{
    std::vector<std::vector<int> >  main, pend;

    // split main and pend vectors
    int tmp;
    size_t i = 2 * level - 1;
    while (i < numbers.size())
    {
        std::vector<int> sub_vec;
        tmp = level;
        size_t  x = i;
        while (tmp > 0 && x < numbers.size())
        {
            sub_vec.insert(sub_vec.begin(), numbers[x]);
            x--;
            tmp--;
        }
        main.push_back(sub_vec);
        i += 2*level;
    }
    i = level - 1;
    while (i < numbers.size()) {
        std::vector<int> sub_vec;
        tmp = level;
        size_t  x = i;
        while (tmp > 0 && x < numbers.size())
        {
            sub_vec.insert(sub_vec.begin(), numbers[x]);
            x--;
            tmp--;
        }
        pend.push_back(sub_vec);
        i += 2*level;
    }
    if (pend.size() > 0)
        main.insert(main.begin(), pend[0]);
    //sorting pend vector using Jacobsthal sequence and binary search
    if (pend.size() > 1)
    {
        std::vector<int> jacob_sequence, jacob_original, jacob_flag, jacob_size;

        jacob_size = generate_jacob_sizes(pend.size());
        int jacob_index = jacobstal_generator(1);
        int jacob_prev = 0;
        int i = 2;

        jacob_sequence.push_back(jacob_index);
        jacob_original.push_back(jacob_index);
        jacob_flag.push_back(1);
        while(jacob_index <= (int)pend.size())
        {
            jacob_prev = jacob_index;
            jacob_index = jacobstal_generator(i);
            if (jacob_index > (int)pend.size())
                break;
            int current = jacob_index;
            jacob_sequence.push_back(current);
            jacob_original.push_back(current);
            jacob_flag.push_back(1);
            while(--current > jacob_prev)
            {
                jacob_sequence.push_back(current);
                jacob_flag.push_back(0);
            }
            i++;
        }
        if (jacob_index == (int)pend.size())
        {
            jacob_sequence.push_back(jacob_index);
            jacob_original.push_back(jacob_index);
            jacob_flag.push_back(1);
        }
        else
        {
            int current = pend.size();
            while(current > jacob_prev)
            {
                jacob_sequence.push_back(current);
                jacob_flag.push_back(0);
                current--;
            }
        }
        for (size_t _ii = 0; _ii < jacob_size.size(); ++_ii)
            std::cout << jacob_size[_ii] << " ";
        std::cout << std::endl;
        int counter = 0;
        int k = 1;
        size_t end = main.size();
        size_t right;

        for (size_t seq_idx = 1; seq_idx < jacob_sequence.size(); ++seq_idx)
        {
            size_t left = 0;

            if (counter == 0 && jacob_flag[seq_idx] == 0)
                end = main.size();
            else if (jacob_flag[seq_idx] == 1)
            {
                counter = jacob_original[k] - jacob_original[k - 1];
                end = (size_t)jacob_size[k];
                k++;
            }
            if (counter > 0 || (counter == 0 && jacob_flag[seq_idx] == 0))
            {
                int pend_index = jacob_sequence[seq_idx] - 1;

                right = end;
                while (left < right)
                {
                    size_t middle = left + (right - left) / 2;

                    if (pend[pend_index].back() < main[middle].back())
                        right = middle;
                    else
                        left = middle + 1;
                }
                if (counter > 0)
                    --counter;
                main.insert(main.begin() + left, pend[pend_index]);
            }
        }
    }
    //merge main vector back to numbers
    std::vector<int> new_vec;
    for (size_t i = 0; i < main.size(); i++)
        for (size_t j = 0; j < main[i].size(); j++)
            new_vec.push_back(main[i][j]);
    size_t o = new_vec.size();
    for (size_t i = o; i < numbers.size(); i++)
        new_vec.push_back(numbers[i]);
    return new_vec;
}


std::vector<int> pairing(std::vector<int> &numbers, int level)
{

    if (level > 1 && (size_t)level > numbers.size()/2)
        return numbers;
    std::vector<int> new_vec;
    for (size_t i = 0; i + 2 * level <= numbers.size(); i += level * 2)
    {
        std::vector<int> group1, group2;
        for (size_t j = i; j < i + level && j < numbers.size(); ++j)
            group1.push_back(numbers[j]);
        for (size_t j = i + level; j < i + 2 * level && j < numbers.size(); ++j)
            group2.push_back(numbers[j]);
        if (group1.back() >= group2.back())
            std::swap(group1, group2);
        for (size_t k = 0; k < group1.size(); k++)
            new_vec.push_back(group1[k]);
        for (size_t k = 0; k < group2.size(); k++)
            new_vec.push_back(group2[k]);
    }
    size_t x = new_vec.size();
    for (size_t i = x; i < numbers.size(); i++)
        new_vec.push_back(numbers[i]);
    level *= 2;
    new_vec = pairing(new_vec, level);
    new_vec = sort_algo(new_vec, level / 2);
    return new_vec;
}



std::deque<int> generate_jacob_sizes_dq(int limit)
{

    //1 3 7 15 31 ...
    //2 ^ (k + 1) - 1
    std::deque<int> jacobsthal_numbers;
    int previous = 1, current = 3;
    
    jacobsthal_numbers.push_back(previous);
    if (current <= limit) {
        jacobsthal_numbers.push_back(current);
    }
    while (current <= limit) {
        int next = 2 * current + 1;
        jacobsthal_numbers.push_back(next);
        previous = current;
        current = next;
    }
    return jacobsthal_numbers;
}


std::deque<int> sort_algo_dq(std::deque<int> &numbers, int level)
{
    std::deque<std::deque<int> >  main, pend;

    // split main and pend vectors
    int tmp;
    size_t i = 2 * level - 1;
    while (i < numbers.size())
    {
        std::deque<int> sub_vec;
        tmp = level;
        size_t  x = i;
        while (tmp > 0 && x < numbers.size())
        {
            sub_vec.insert(sub_vec.begin(), numbers[x]);
            x--;
            tmp--;
        }
        main.push_back(sub_vec);
        i += 2*level;
    }
    i = level - 1;
    while (i < numbers.size()) {
        std::deque<int> sub_vec;
        tmp = level;
        size_t  x = i;
        while (tmp > 0 && x < numbers.size())
        {
            sub_vec.insert(sub_vec.begin(), numbers[x]);
            x--;
            tmp--;
        }
        pend.push_back(sub_vec);
        i += 2*level;
    }
    if (pend.size() > 0)
        main.insert(main.begin(), pend[0]);
    //sorting pend deque using Jacobsthal sequence and binary search
    if (pend.size() > 1)
    {
        std::deque<int> jacob_sequence, jacob_original, jacob_flag, jacob_size;

        jacob_size = generate_jacob_sizes_dq(pend.size());
        int jacob_index = jacobstal_generator(1);
        int jacob_prev = 0;
        int i = 2;

        jacob_sequence.push_back(jacob_index);
        jacob_original.push_back(jacob_index);
        jacob_flag.push_back(1);
        while(jacob_index <= (int)pend.size())
        {
            jacob_prev = jacob_index;
            jacob_index = jacobstal_generator(i);
            if (jacob_index > (int)pend.size())
                break;
            int current = jacob_index;
            jacob_sequence.push_back(current);
            jacob_original.push_back(current);
            jacob_flag.push_back(1);
            while(--current > jacob_prev)
            {
                jacob_sequence.push_back(current);
                jacob_flag.push_back(0);
            }
            i++;
        }
        if (jacob_index == (int)pend.size())
        {
            jacob_sequence.push_back(jacob_index);
            jacob_original.push_back(jacob_index);
            jacob_flag.push_back(1);
        }
        else
        {
            int current = pend.size();
            while(current > jacob_prev)
            {
                jacob_sequence.push_back(current);
                jacob_flag.push_back(0);
                current--;
            }
        }
        for (size_t _ii = 0; _ii < jacob_size.size(); ++_ii)
            std::cout << jacob_size[_ii] << " ";
        std::cout << std::endl;
        int counter = 0;
        int k = 1;
        size_t end = main.size();
        size_t right;

        for (size_t seq_idx = 1; seq_idx < jacob_sequence.size(); ++seq_idx)
        {
            size_t left = 0;

            if (counter == 0 && jacob_flag[seq_idx] == 0)
                end = main.size();
            else if (jacob_flag[seq_idx] == 1)
            {
                counter = jacob_original[k] - jacob_original[k - 1];
                end = (size_t)jacob_size[k];
                k++;
            }
            if (counter > 0 || (counter == 0 && jacob_flag[seq_idx] == 0))
            {
                int pend_index = jacob_sequence[seq_idx] - 1;

                right = end;
                while (left < right)
                {
                    size_t middle = left + (right - left) / 2;

                    if (pend[pend_index].back() < main[middle].back())
                        right = middle;
                    else
                        left = middle + 1;
                }
                if (counter > 0)
                    --counter;
                main.insert(main.begin() + left, pend[pend_index]);
            }
        }
    }
    //merge main deque back to numbers
    std::deque<int> new_vec;
    for (size_t i = 0; i < main.size(); i++)
        for (size_t j = 0; j < main[i].size(); j++)
            new_vec.push_back(main[i][j]);
    size_t o = new_vec.size();
    for (size_t i = o; i < numbers.size(); i++)
        new_vec.push_back(numbers[i]);
    return new_vec;
}


std::deque<int> pairing_dq(std::deque<int> &numbers, int level)
{

    if (level > 1 && (size_t)level > numbers.size()/2)
        return numbers;
    std::deque<int> new_vec;
    for (size_t i = 0; i + 2 * level <= numbers.size(); i += level * 2)
    {
        std::deque<int> group1, group2;
        for (size_t j = i; j < i + level && j < numbers.size(); ++j)
            group1.push_back(numbers[j]);
        for (size_t j = i + level; j < i + 2 * level && j < numbers.size(); ++j)
            group2.push_back(numbers[j]);
        if (group1.back() >= group2.back())
            std::swap(group1, group2);
        for (size_t k = 0; k < group1.size(); k++)
            new_vec.push_back(group1[k]);
        for (size_t k = 0; k < group2.size(); k++)
            new_vec.push_back(group2[k]);
    }
    size_t x = new_vec.size();
    for (size_t i = x; i < numbers.size(); i++)
        new_vec.push_back(numbers[i]);
    level *= 2;
    new_vec = pairing_dq(new_vec, level);
    new_vec = sort_algo_dq(new_vec, level / 2);
    return new_vec;
}
