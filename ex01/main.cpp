/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouriga <alouriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 03:17:22 by alouriga          #+#    #+#             */
/*   Updated: 2025/03/06 23:12:24 by alouriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"


int main(int ac, char **av)
{
    if (ac != 1)
        return (1);
    else{
        std::string str;
        phonebook Phonebook;
        while (1)
        {
            std::cout << "entre the command line ! : "
            if (std::getline(std::cin, str).eof())
            {
                std::cout << "error in input";
                return (1);
            }
            else{
                if (str == "ADD")
                    Phonebook.add();
                else if (str == "SEARCH")
                {
                    Phonebook.search();
                }
                    //
                    
                else
                {
                    std::cout << "< command not found pls try a valid command >\n";
                }
            }
        }
    
    }
}