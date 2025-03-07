/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouriga <alouriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 03:23:30 by alouriga          #+#    #+#             */
/*   Updated: 2025/03/06 23:07:02 by alouriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <cstdlib> 

PhoneBook::PhoneBook()
{
    index = 0;
    size = 0;
}
PhoneBook::~PhoneBook()
{
    
}

int	ft_isalpha(std::string str)
{
	int	i;

	i = 0;
    while(str[i] != '\0')
    {
	    if (!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || str[i] == ' ' || str[i] == '\t'))
        {
		    return(0);
        }
        i++;
    }
        
	return (1);
}


int check_space(std::string str)
{
    int i = 0;
    int j = 0;
    while (str[i] != '\0')
    {
        if (str[i] == ' ' || str[i] == '\t')
            j++;
        i++;
    }
    if (i == j)
        return (0);
    return(1); 
}

int check_string(std::string str)
{
        if (!check_space(str))
            return(0);
        if (!ft_isalpha(str))
            return(0);
    return(1);
}

int check_number(std::string str)
{
    for(size_t i = 0; i < str.length(); i++)
    {
        if (!isdigit(str[i]))
            return(0);
    }
    return(1);
}
int check_number_2(std::string str)
{
    for(size_t i = 0; i < str.length(); i++)
    {
        if (!isdigit(str[i]))
            return(0);
        if (i > 0)
            return(0);
    }
    return(1);
}

void PhoneBook::add()
{
    if(index == 8)
        index = index % 8;
        
    std::string str;


    CHECKPOINT:
    std::cout << "enter the first name : ";
    if(std::getline(std::cin, str).eof())
    {
        std::cout << "error in the input\n";
        return;
    }
    if (str.empty()) {
        std::cout << "Error: The first name cannot be empty.\n";
        goto CHECKPOINT;
    }
    if (!check_string(str))
    {
        std::cout << "error in the first name\n";
        goto CHECKPOINT;
    }
    cts[index].set_first_name(str);
    

    

    
    CHECKPOINT_2:
    std::cout << "enter the last name : ";
    if(std::getline(std::cin, str).eof())
    {
        std::cout << "error in the input\n";
        return;
    }
    if (str.empty()) {
        std::cout << "Error: The last name cannot be empty.\n";
        goto CHECKPOINT_2;
    }
    if (!check_string(str))
    {
        std::cout << "error in the last name\n";
        goto CHECKPOINT_2;
    }
    cts[index].set_last_name(str);

    CHECKPOINT_3:
    std::cout << "enter the nickname : ";
    if(std::getline(std::cin, str).eof())
    {
        std::cout << "error in the input\n";
        return;
    }
    if (str.empty()) {
        std::cout << "Error: The nickname cannot be empty.\n";
        goto CHECKPOINT_3;
    }
    if (!check_space(str))
    {
        std::cout << "Error: The nickname cannot be empty.\n";
        goto CHECKPOINT_3;
    }
    cts[index].set_nickname(str);
    


    

    CHECKPOINT_4:
    std::cout << "enter the phone number : ";
    if(std::getline(std::cin, str).eof())
    {
        std::cout << "error in the input\n";
        return;
    }
    if (str.empty()) {
        std::cout << "Error: The number phone cannot be empty.\n";
        goto CHECKPOINT_4;
    }
    if (!check_number(str))
    {
        std::cout << "error in the number\n";
        goto CHECKPOINT_4;
    }
    cts[index].set_phone_number(str);



    CHECKPOINT_5:
     std::cout << "enter the darkest secret: ";
    if(std::getline(std::cin, str).eof())
    {
        std::cout << "error in the input\n";
        return;
    }
    if (str.empty()) {
        std::cout << "Error: The darkest secret cannot be empty.\n";
        goto CHECKPOINT_5;
    }
    if (!check_space(str))
    {
        std::cout << "Error: The darkest secret cannot be empty.\n";
        goto CHECKPOINT_5;
    }
    cts[index].set_darkest_secret(str);
    index++;
    if (size < 8)
        size++;
}


std::string string_length(std::string str)
{
    if (str.length() > 10)
    {
        return (str.substr(0, 9) + ".");
    }
    return (str);
}

void    PhoneBook::search()
{
    std::string str;
    int i;
    if (index == 0)
    {
        std::cout << "there are no valid contact \n";
        return;
    }
    std::cout << "---------------------------------------------\n";
    std::cout << "|   Index  |First Name| Last Name| Nickname |\n";
    std::cout << "---------------------------------------------\n";
    for(int i = 0;i < 8 && !cts[i].get_first_name().empty(); i++){
       std::cout << "| " << std::setw(8) << i << " |"
          << std::setw(10) << string_length(cts[i].get_first_name()) << "|"
          << std::setw(10) << string_length(cts[i].get_last_name()) << "|"
          << std::setw(10) << string_length(cts[i].get_nickname()) << "|\n";
    }
    std::cout << "---------------------------------------------\n";

    std::cout << "set a index for more info : ";
    if(std::getline(std::cin, str).eof())
    {
        std::cout << "error in the input\n";
        return;
    }
    if (str.empty()) {
        std::cout << "Error: The number phone cannot be empty.\n";
        return;
    }
    if (!check_number_2(str))
    {
        std::cout << "error in the number\n";
        return;
    }
    i = str[0] - '0';
    if (i > 8)
    {
        std::cout << "error in the number\n";
        return;
    }
    if (i >= size)
    {
        std::cout << "the conatct not available\n";
        return;
    }
        std::cout << "first name : " << cts[i].get_first_name() << "\n";
        std::cout << "last name : " << cts[i].get_last_name() << "\n";
        std::cout << "nickname : " << cts[i].get_nickname() << "\n";
        std::cout << "phone number : " << cts[i].get_phone_number() << "\n";
        std::cout << "darkest secret : " << cts[i].get_darkest_secret() << "\n";
    
}


void    PhoneBook::ft_exit()
{
    exit(0);
}