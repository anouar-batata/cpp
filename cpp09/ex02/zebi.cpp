// #include <iostream>
// #include <vector>
// #include <algorithm>

// void parse_input(char **argv)
// {
//     int i = 0;
//     while (argv && argv[i])
//     {
//         std::string input = argv[i];
//         for (size_t j = 0; j < input.length(); j++)
//         {
//             if (!std::isdigit(input[j]))
//             {
//                 std::cerr << "Error" << std::endl;
//                 exit(1);
//             }
//         }
//         i++;
//     }
    
// }

// std::vector<int> generate_jacob_sizes(int limit)
// {

//     //1 3 7 15 31 ...
//     //2 ^ (k + 1) - 1
//     std::vector<int> jacobsthal_numbers;
//     int previous = 1, current = 3;
    
//     jacobsthal_numbers.push_back(previous);
//     if (current <= limit) {
//         jacobsthal_numbers.push_back(current);
//     }
//     while (current <= limit) {
//         int next = 2 * current + 1;
//         jacobsthal_numbers.push_back(next);
//         previous = current;
//         current = next;
//     }
//     return jacobsthal_numbers;
// }

// int jacobstal_generator(int n)
// {
//     //1  3 5  11  21  43 ...
//     if (n == 0 || n == 1)
//         return 1;
//     return  jacobstal_generator(n - 1) + 2 * jacobstal_generator(n - 2);
// }

// std::vector<int> sort_algo(std::vector<int> &numbers, int level)
// {
//     std::vector<std::vector<int> >  main, pend;

//     for (size_t i = 0; i <= numbers.size(); i += level * 2)
//     {
//         std::vector<int> group1, group2;
//         if (i + level > numbers.size() )
//             break;
//         for (size_t j = i; j < i + level && j < numbers.size(); ++j)
//             group1.push_back(numbers[j]);
//         for (size_t j = i + level; j < i + 2 * level && j < numbers.size(); ++j)
//             group2.push_back(numbers[j]);
//         if (i == 0)
//             main.push_back(group1);
//         main.push_back(group2);
//         pend.push_back(group1);
//     }

//     if (pend.size() > 1)
//     {
//         std::vector<int> jacob_sequence, jacob_original, jacob_flag, jacob_size;

//         jacob_size = generate_jacob_sizes(pend.size());
//         int jacob_index = jacobstal_generator(1);
//         int jacob_prev = 0;
//         int i = 2;

//         jacob_sequence.push_back(jacob_index);
//         jacob_original.push_back(jacob_index);
//         jacob_flag.push_back(1);
//         while(jacob_index <= (int)pend.size())
//         {
//             jacob_prev = jacob_index;
//             jacob_index = jacobstal_generator(i);
//             if (jacob_index > (int)pend.size())
//                 break;
//             int current = jacob_index;
//             jacob_sequence.push_back(current);
//             jacob_original.push_back(current);
//             jacob_flag.push_back(1);
//             while(--current > jacob_prev)
//             {
//                 jacob_sequence.push_back(current);
//                 jacob_flag.push_back(0);
//             }
//             i++;
//         }
//         if (jacob_index == (int)pend.size())
//         {
//             jacob_sequence.push_back(jacob_index);
//             jacob_original.push_back(jacob_index);
//             jacob_flag.push_back(1);
//         }
//         else
//         {
//             int current = pend.size();
//             while(current > jacob_prev)
//             {
//                 jacob_sequence.push_back(current);
//                 jacob_flag.push_back(0);
//                 current--;
//             }
//         }

//         //insert pend into main according to jacob_sequence
//         int counter = 0;
//         int k = 1;
//         int end = main.size();
//         int right;
//         std::cout << "level =" << level << std::endl;
//         for (size_t i = 1; i < pend.size(); i++)
//         {
//             int middle;
//             int left = 0;
            
//             if (counter == 0 && jacob_flag[i] == 0)
//                 end = main.size() -1;
//             else
//             {
//                 if (jacob_flag[i] == 1)
//                 {
//                     counter = jacob_original[k] - jacob_original[k -1];
//                     end = jacob_size[k];
//                     k++;
//                 }
//             }
//             std::cout << "counter = " << counter << std::endl;
//             if(counter > 0 || (counter == 0 && jacob_flag[i] == 0))
//             {
//                 right = end;
//                 while (left < right)
//                 {
//                     middle = (right +left) / 2;
//                     std::cout << "left = " << left << " middle = " << middle << " right = " << right << std::endl;
//                     if (pend[jacob_sequence[i] -1].back() < main[middle].back())
//                         right = middle;
//                     else
//                     {
//                         left = middle + 1;
//                     }
//                 }
//                 std::cout << "Inserting  " << pend[jacob_sequence[i]-1].back() << " from pend[" << i << "] into main at position " << left << std::endl;
//                 counter--;
//                 main.insert(main.begin() + left, pend[jacob_sequence[i] -1]);
//             }
//         }
//     }
//     std::vector<int> new_vec;
//     for (size_t i = 0; i < main.size(); i++)
//         for (size_t j = 0; j < main[i].size(); j++)
//             new_vec.push_back(main[i][j]);
//     if( new_vec.size() < numbers.size())
//     {
//         for (size_t i = new_vec.size(); i < numbers.size(); i++)
//             new_vec.push_back(numbers[i]);
//     }
//     return new_vec;
// }























































































































































































































bool is_sorted(std::vector<int> &numbers)
{
    for (size_t i = 0; i < numbers.size() - 1; i++)
    {
        if (numbers[i] > numbers[i + 1])
            return false;
    }
    return true;
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
    //print new_vec
    // std::cout << "After pairing level " << level / 2 << ": ";
    // for (size_t i = 0; i < new_vec.size(); i++)
    //     std::cout << new_vec[i] << " ";
    // std::cout << std::endl;
    new_vec = sort_algo(new_vec, level / 2);
    return new_vec;
}



// int main(int argc, char **argv)
// {
//     if (argc == 1)
//     {
//         std::cerr << "not enough arguments" << std::endl;
//         return 1;
//     }
//     parse_input(&argv[1]);
//     std::vector<int> numbers;
//     for (int i = 1; i < argc; i++)
//         numbers.push_back(atoi(argv[i]));
//     std::cout << "Unsorted sequence: ";
//     for (size_t i = 0; i < numbers.size(); i++)
//         std::cout << numbers[i] << " ";
//     std::cout << std::endl;
//     numbers = pairing(numbers, 1);
//     std::cout << "Sorted sequence: ";
//     for (size_t i = 0; i < numbers.size(); i++)
//         std::cout << numbers[i] << " ";
//     std::cout << std::endl;
//     // numbers.push_back(42); // to test failure
//     if (!is_sorted(numbers))
//     {
//         std::cerr << "Error: sequence is not sorted" << std::endl;
//         exit(1);
//     }
//     return 0;
// }







// #include <iostream>
// #include <vector>
// #include <algorithm>

// void parse_input(char **argv)
// {
//     int i = 0;
//     while (argv && argv[i])
//     {
//         std::string input = argv[i];
//         for (size_t j = 0; j < input.length(); j++)
//         {
//             if (!std::isdigit(input[j]))
//             {
//                 std::cerr << "Error" << std::endl;
//                 exit(1);
//             }
//         }
//         i++;
//     }
    
// }

// std::vector<int> generate_jacob_sizes(int limit)
// {

//     //1 3 7 15 31 ...
//     //2 ^ (k + 1) - 1
//     std::vector<int> jacobsthal_numbers;
//     int previous = 1, current = 3;
    
//     jacobsthal_numbers.push_back(previous);
//     if (current <= limit) {
//         jacobsthal_numbers.push_back(current);
//     }
//     while (current <= limit) {
//         int next = 2 * current + 1;
//         jacobsthal_numbers.push_back(next);
//         previous = current;
//         current = next;
//     }
//     return jacobsthal_numbers;
// }

// int jacobstal_generator(int n)
// {
//     //1  3 5  11  21  43 ...
//     if (n == 0 || n == 1)
//         return 1;
//     return  jacobstal_generator(n - 1) + 2 * jacobstal_generator(n - 2);
// }

// std::vector<int> sort_algo(std::vector<int> &numbers, int level)
// {
//     std::vector<std::vector<int> >  main, pend;

//     for (size_t i = 0; i <= numbers.size(); i += level * 2)
//     {
//         std::vector<int> group1, group2;
//         if (i + level > numbers.size() )
//             break;
//         for (size_t j = i; j < i + level && j < numbers.size(); ++j)
//             group1.push_back(numbers[j]);
//         for (size_t j = i + level; j < i + 2 * level && j < numbers.size(); ++j)
//             group2.push_back(numbers[j]);
//         if (i == 0)
//             main.push_back(group1);
//         main.push_back(group2);
//         pend.push_back(group1);
//     }

//     if (pend.size() > 1)
//     {
//         std::vector<int> jacob_sequence, jacob_original, jacob_flag, jacob_size;

//         jacob_size = generate_jacob_sizes(pend.size());
//         int jacob_index = jacobstal_generator(1);
//         int jacob_prev = 0;
//         int i = 2;

//         jacob_sequence.push_back(jacob_index);
//         jacob_original.push_back(jacob_index);
//         jacob_flag.push_back(1);
//         while(jacob_index <= (int)pend.size())
//         {
//             jacob_prev = jacob_index;
//             jacob_index = jacobstal_generator(i);
//             if (jacob_index > (int)pend.size())
//                 break;
//             int current = jacob_index;
//             jacob_sequence.push_back(current);
//             jacob_original.push_back(current);
//             jacob_flag.push_back(1);
//             while(--current > jacob_prev)
//             {
//                 jacob_sequence.push_back(current);
//                 jacob_flag.push_back(0);
//             }
//             i++;
//         }
//         if (jacob_index == (int)pend.size())
//         {
//             jacob_sequence.push_back(jacob_index);
//             jacob_original.push_back(jacob_index);
//             jacob_flag.push_back(1);
//         }
//         else
//         {
//             int current = pend.size();
//             while(current > jacob_prev)
//             {
//                 jacob_sequence.push_back(current);
//                 jacob_flag.push_back(0);
//                 current--;
//             }
//         }

//         // insert pend into main according to jacob_sequence
//         int counter = 0;
//         int k = 1;
//         size_t end = main.size();
//         size_t right;
//         std::cout << "level =" << level << std::endl;
//         // Iterate over jacob_sequence (it drives which pend index to insert)
//         for (size_t seq_idx = 1; seq_idx < jacob_sequence.size(); ++seq_idx)
//         {
//             size_t left = 0;
//             // jacob_flag and jacob_sequence are parallel arrays built above
//             if (counter == 0 && jacob_flag[seq_idx] == 0)
//                 end = main.size(); // exclusive bound
//             else if (jacob_flag[seq_idx] == 1)
//             {
//                 // set how many insertions to perform in this block and the search bound
//                 counter = jacob_original[k] - jacob_original[k - 1];
//                 end = (size_t)jacob_size[k];
//                 k++;
//             }
//             std::cout << "counter = " << counter << std::endl;
//             if (counter > 0 || (counter == 0 && jacob_flag[seq_idx] == 0))
//             {
//                 // safe access: determine pend index from sequence
//                 int pend_index = jacob_sequence[seq_idx] - 1;
//                 if (pend_index < 0 || pend_index >= (int)pend.size())
//                 {
//                     std::cerr << "Warning: jacob_sequence index out of range: " << pend_index << std::endl;
//                     continue;
//                 }
//                 if (pend[pend_index].empty())
//                 {
//                     // nothing to insert
//                     continue;
//                 }
//                 right = end;
//                 while (left < right)
//                 {
//                     size_t middle = left + (right - left) / 2;
//                     std::cout << "left = " << left << " middle = " << middle << " right = " << right << std::endl;
//                     // protect against empty inner vectors in main
//                     if (main[middle].empty() || pend[pend_index].back() < main[middle].back())
//                         right = middle;
//                     else
//                         left = middle + 1;
//                 }
//                 std::cout << "Inserting " << pend[pend_index].back() << " from pend[" << pend_index << "] into main at position " << left << std::endl;
//                 if (counter > 0)
//                     --counter;
//                 main.insert(main.begin() + left, pend[pend_index]);
//             }
//         }
//     }
//     std::vector<int> new_vec;
//     for (size_t i = 0; i < main.size(); i++)
//         for (size_t j = 0; j < main[i].size(); j++)
//             new_vec.push_back(main[i][j]);
//     if( new_vec.size() < numbers.size())
//     {
//         for (size_t i = new_vec.size(); i < numbers.size(); i++)
//             new_vec.push_back(numbers[i]);
//     }
//     return new_vec;
// }























































































































































































































// bool is_sorted(std::vector<int> &numbers)
// {
//     for (size_t i = 0; i < numbers.size() - 1; i++)
//     {
//         if (numbers[i] > numbers[i + 1])
//             return false;
//     }
//     return true;
// }









// std::vector<int> pairing(std::vector<int> &numbers, int level)
// {

//     if (level > 1 && (size_t)level > numbers.size()/2)
//         return numbers;
//     std::vector<int> new_vec;
//     for (size_t i = 0; i + 2 * level <= numbers.size(); i += level * 2)
//     {
//         std::vector<int> group1, group2;
//         for (size_t j = i; j < i + level && j < numbers.size(); ++j)
//             group1.push_back(numbers[j]);
//         for (size_t j = i + level; j < i + 2 * level && j < numbers.size(); ++j)
//             group2.push_back(numbers[j]);
//         if (group1.back() >= group2.back())
//             std::swap(group1, group2);
//         for (size_t k = 0; k < group1.size(); k++)
//             new_vec.push_back(group1[k]);
//         for (size_t k = 0; k < group2.size(); k++)
//             new_vec.push_back(group2[k]);
//     }
//     size_t x = new_vec.size();
//     for (size_t i = x; i < numbers.size(); i++)
//         new_vec.push_back(numbers[i]);
//     level *= 2;
//     new_vec = pairing(new_vec, level);
//     //print new_vec
//     // std::cout << "After pairing level " << level / 2 << ": ";
//     // for (size_t i = 0; i < new_vec.size(); i++)
//     //     std::cout << new_vec[i] << " ";
//     // std::cout << std::endl;
//     new_vec = sort_algo(new_vec, level / 2);
//     return new_vec;
// }



